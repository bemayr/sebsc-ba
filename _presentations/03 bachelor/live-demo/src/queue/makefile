TARGET = main

# compiler settings
CC      = g++
CCFLAGS = -std=c++14 -pedantic -Wall -Wconversion -Wextra

# linker/loader settings
LD      = g++
LDFLAGS = -lm   # link math library for <math.h>

# names of all .c and .o files
CFILES  = $(wildcard *.cpp)  # $(..) works for gmake only
OFILES  = $(CFILES:.cpp=.o)  # $(..) works for gmake only

# name of file containing all generated dependencies
DEPENDFILE = .depends

# rule how to compile .o files from .c files
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $<

all: $(TARGET)

# main target: prg is the name of the executable to build
$(TARGET): $(OFILES)
	$(LD) -o $@ $(OFILES) $(LDFLAGS)

# clean up directory
clean:
	rm -f $(TARGET) core *.o *..c *% %.bak %.BAK *~

# create dependencies using gcc -MM
depend:
	@$(CC) $(CCFLAGS) -MM $(CFILES) > $(DEPENDFILE)

# or alternatively use makedepend if it exists
#depend:
#	makedepend -Y -- $(CCFLAGS) -- $(CFILES) 2>/dev/null

-include $(DEPENDFILE)
