# makefile - Make scanx OS/2 OpenWatcom VIO c/cpp app with standard options

# 2012-05-24 SHL - clone from elsewhere

# Assumes
# set INCLUDE=*;D:\WATCOM\H;D:\TOOLKIT\H
# set LIB=*;D:\TOOLKIT\LIB;;D:\WATCOM\LIB386\OS2;D:\WATCOM\LIB386

# Required environment variables
# WATCOM
# VENDOR
# BUILDVER
# BUILDMACH
# BUILDTIME

# Supported environment variables
# Define DEBUG in environment for debug build
# Define EXCEPTQ in environment to build with exceptq support
# Define WARN to allow warnings

# Check required environment variables

!ifndef %WATCOM
!error WATCOM not defined
!endif

!ifndef %BUILDTIME
!error BUILDTIME not defined
!endif

!ifndef %BUILDVER
!error BUILDVER not defined
!endif

!ifndef %BUILDMACH
!error BUILDMACH not defined
!endif

!ifndef %VENDOR
!error VENDOR not defined
!endif

.ERASE

.SUFFIXES:
.SUFFIXES: .sys .obj .asm .inc .def .lrf .ref .lst .sym .map .c .cpp .h .lib

NAME = scanx
DESC = scanx VIO
EXENAME = $(NAME)
MAKEFILE = makefile

#?    set H=$(%B)\h
#?    set INCLUDE=$(%R);$(%H);$(%W);

CC = wcc386
CPP = wpp386
ASM = wasm

!ifndef DEBUG			# if not defined on wmake command line
!ifdef %DEBUG			# if defined in environment
DEBUG = $(%DEBUG)		# use value from environment
!endif
!endif

!ifndef WARN		# if not defined on wmake command line
!ifdef %WARN		# if defined in environment
WARN = $(%WARN)	# use value from environment
!endif
!endif

!ifndef EXCEPTQ			# if not defined on wmake command line
!ifdef %EXCEPTQ			# if defined in environment
EXCEPTQ = $(%EXCEPTQ)		# use value from environment
!endif
!endif

# wcc/wpp flags
# -bc           console app
# -bd		build target is a Dynamic Link Library (DLL) (see bd)
# -bm           multithread libs
# -bt=os2       target
# -d2           full debug
# -hd           dwarf
# -j		signed char
# -mf           flat
# -of           generate traceable stack frames
# -olinars      optimze loops, inline, e(n)able fp recip, relax (a)lias, reordering, space
# -s            disable stack checks
# -sg	generate calls to grow the stack
# -st           touch stack through SS first
# -wcd14	no reference to symbol
# -wcd726	no reference to formal parameter
# -we		treat warnings as errors
# -wx           max warnings
# -ze           define _cdecl etc.
# -zfp          disable fs use
# -zgp          disable gs use
# -zp4          align 4
# -zq           quiet

# Order dependent flags
!ifdef DEBUG
# CFLAGS = -bt=os2 -mf -bm     -olirs -d2 -s -j -wx -zfp -zgp -zp4 -hd
# CFLAGS = -bt=os2 -mf -bm -of -olirs -d2 -s -j -wx -zfp -zgp -zp4 -hd
CFLAGS = -bt=os2 -mf -bm -of -olirs -d2 -s -j -wx -zfp -zgp      -hd
CPPFLAGS = -bm -sg -bc -bt=os2 -mf -of -olinars -d2 -s -j -wx -zfp -zgp -zp4 -hd

!else
# CFLAGS =   -bt=os2 -bm -mf -of -olirs     -s -j -wx -zfp -zgp -zp4 -hd
CFLAGS =   -bt=os2 -bm -mf -of -olirs     -s -j -wx -zfp -zgp      -hd
CPPFLAGS = -sg -bc -bt=os2 -mf -bm -of -olinars     -s -j -wx -zfp -zgp -zp4 -hd
!endif

# Order independent flags
CFLAGS += -zq
CPPFLAGS += -zq
CFLAGS += -wcd14 -wcd726
CPPFLAGS += -wcd14 -wcd726

!ifndef WARN
CFLAGS += -we
CPPFLAGS += -we
!endif

!ifdef EXCEPTQ
CFLAGS += -dEXCEPTQ
CPPFLAGS += -dEXCEPTQ
!endif

# wasm flags
# -3p		80386 protected mode instructions
# -d1           line number debugging support
# -o            allow C form of octal constants
# -zq           quiet

# Order dependent wasm flags
!ifdef DEBUG
AFLAGS = -d1 -3p -o
!else
AFLAGS =     -3p -o
!endif

!ifndef AINC			# if not defined on wmake command line
!ifdef %AINC			# if defined in environment
AINC = $(%AINC)			# use value from environment
!else
AINC = d:\ddk\base\inc		# assume
!endif
!endif

# Order independent wasm flags
AFLAGS += -i=$(AINC)

AFLAGS += -zq

LINK = wlink

#################
# Inference rules
#################

.c.obj: .AUTODEPEND $(MAKEFILE)
     $(CC) $(CFLAGS) $*.c

.cpp.obj: .AUTODEPEND $(MAKEFILE)
     $(CPP) $(CPPFLAGS) $*.cpp

.asm.obj: .AUTODEPEND $(MAKEFILE)
     $(ASM) $(AFLAGS) $*.asm

##############
# Object files
##############

# objects built here
OBJS=$(NAME).obj

# objects built elsewhere
EXTRA_OBJS=

# all object files
ALL_OBJS=$(OBJS) $(EXTRA_OBJS)

#############
# Build rules
#############

all: $(EXENAME).exe

# Avoid lost spaces in @%write
FILL = xxxx

$(NAME).lrf: $(MAKEFILE)
   @%write $^@ system os2v2
   @%write $^@ option verbose
   @%write $^@ option cache
   @%write $^@ option caseexact
   @%write $^@ option stack=0x100c00
!ifdef DEBUG
    @%write $^@ debug dwarf all
!endif
   @%write $^@ option map
   @%write $^@ op desc '@$#$(%VENDOR):$(%BUILDVER)$#@$#$#1$#$# $(%BUILDTIME) $(FILL:x= ) $(%BUILDMACH)::EN:US:0:U:@@$(DESC)'
   @%write $^@ name $(NAME)
   @for %f in ($(ALL_OBJS)) do @%append $^@ file %f
!ifdef EXCEPTQ
    @%write $^@ file exceptq.lib
!endif
   @%write $^@ library os2386.lib

$(EXENAME).exe: $(OBJS) $(MAKEFILE) $(NAME).lrf
   $(LINK) @$(NAME).lrf

lxlite: $(EXENAME).exe .symbolic
    dir $<
    lxlite -X- -B- $<
    bldlevel $<
    dir $<

distclean: .symbolic
  -del $(NAME).err
  -del $(NAME).lrf
  -del $(NAME).map
  -del $(NAME).mbr
  -del $(NAME).sym
  -del $(OBJS)

clean: distclean .symbolic
  -del $(EXENAME).exe

settings: .SYMBOLIC
  @echo MAKE is $MAKE
  @echo __VERSION__ is $__VERSION__
  @echo MAKEOPTS is $__MAKEOPTS__
  @echo MAKEFILES is $__MAKEFILES__
  @echo __LOADDLL__ is $__LOADDLL__
