# Compiler and flags
CC = cc
CFLAGS = -g -Wall -ansi -fno-common

# Target executable
TARGET = mcml

# Source files and corresponding object files
SRCS = mcmlgo.c mcmlio.c mcmlmain.c
OBJS = $(SRCS:.c=.o)

# Libraries
LIBS = -lm

# Default target
all: $(TARGET)

mcml.exe:
	make clean
	make CC="x86_64-w64-mingw32-gcc" mcml

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Rule to compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean targets
clean:
	$(RM) $(OBJS)

realclean: clean
	$(RM) $(TARGET)
	$(RM) $(TARGET).exe

# Phony targets
.PHONY: all clean realclean
