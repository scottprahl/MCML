# Compiler and flags
CC = cc
CFLAGS = -g -Wall -ansi -fno-common

# Target executable
TARGET = mcml1 conv1

# Source files and corresponding object files
M_SRCS = mcmlgo.c mcmlio.c mcmlmain.c mcmlnr.c
M_OBJS = $(M_SRCS:.c=.o)

C_SRCS = convconv.c  convi.c conviso.c convmain.c convnr.c convo.c
C_OBJS = $(C_SRCS:.c=.o)

# Libraries
LIBS = -lm

# Default target
all: $(TARGET)

mcml1.exe:
	make clean
	make CC="x86_64-w64-mingw32-gcc" mcml1

conv1.exe:
	make clean
	make CC="x86_64-w64-mingw32-gcc" conv1

# Rule to build the executable
mcml1: $(M_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

conv1: $(C_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Rule to compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean targets
clean:
	rm -rf $(M_OBJS)
	rm -rf $(C_OBJS)

realclean: clean
	rm -rf mcml1
	rm -rf mcml1.exe
	rm -rf conv1
	rm -rf conv1.exe

# Phony targets
.PHONY: all clean realclean
