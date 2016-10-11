ROOT=..
PLATFORM=$(sh $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

PROGS = doatexit echoarg getrlimit testjmp

all:    $(PROGS) opendata.0 scope.0

$(PROGS):   $(LIBAPUE)
	    $(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)
clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc
