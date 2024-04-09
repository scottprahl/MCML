# Compiler and flags
CC = cc
CFLAGS = -g -Wall -ansi -fno-common

# Target executable
TARGET = conv

# Source files and corresponding object files
SRCS = convconv.c  convi.c conviso.c convlib.c convmain.c  convo.c
OBJS = $(SRCS:.c=.o)

# Libraries
LIBS = -lm

# Default target
all: $(TARGET)

conv.exe:
	make clean
	make CC="x86_64-w64-mingw32-gcc" conv

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
