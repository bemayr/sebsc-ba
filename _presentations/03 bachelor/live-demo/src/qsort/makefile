TARGET = main

# compiler settings
CC      = gcc
CCFLAGS = -ansi -pedantic -g -Wall

# linker/loader settings
LD      = gcc
LDFLAGS =

# names of all .c and .o files
CFILES  = $(wildcard *.c)  # $(..) works for gmake only
OFILES  = $(CFILES:.c=.o)  # $(..) works for gmake only

# name of file containing all generated dependencies
DEPENDFILE = .depends

# rule how to compile .o files from .c files
%.o: %.c
	$(CC) $(CCFLAGS) -c $<

all: $(TARGET)

# main target: prg is the name of the executable to build
$(TARGET): $(OFILES)
	$(LD) -o $@ $(OFILES) $(LDFLAGS)

# clean up directory
clean:
	rm -f $(TARGET) core *.o *..c *% %.bak %.BAK *~

# create dependency rules using gcc -MM
depend:
	@$(CC) $(CCFLAGS) -MM $(CFILES) > $(DEPENDFILE)

# or alternatively use makedepend if it exists
#depend:
#	makedepend -Y -- $(CCFLAGS) -- $(CFILES) 2>/dev/null

-include $(DEPENDFILE)
