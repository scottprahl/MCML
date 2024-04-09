# Compiler and flags
CC = cc
CFLAGS = -g -Wall -ansi -fno-common
WINCC = x86_64-w64-mingw32-gcc
INDENT_OPT = -br -brs -nbs -ci4 -cli0 -bli0 -l120 -ncdb -nce -nlp -npcs -npsl -i4 -nut

# Source files and corresponding object files
SRCS = convconv.c  convi.c conviso.c convlib.c convmain.c  convo.c
OBJS = $(SRCS:.c=.o)

# Libraries
LIBS = -lm

all: conv

exe: conv.exe

conv:
	$(CC) $(CFLAGS) -c convconv.c -o convconv.o
	$(CC) $(CFLAGS) -c convi.c -o convi.o
	$(CC) $(CFLAGS) -c conviso.c -o conviso.o
	$(CC) $(CFLAGS) -c convlib.c -o convlib.o
	$(CC) $(CFLAGS) -c convmain.c -o convmain.o
	$(CC) $(CFLAGS) -c convo.c -o convo.o
	$(CC) $(CFLAGS) -o conv convconv.o convi.o conviso.o convlib.o convmain.o convo.o -lm


conv.exe:
	$(WINCC) $(CFLAGS) -c convconv.c -o convconv.o
	$(WINCC) $(CFLAGS) -c convi.c -o convi.o
	$(WINCC) $(CFLAGS) -c conviso.c -o conviso.o
	$(WINCC) $(CFLAGS) -c convlib.c -o convlib.o
	$(WINCC) $(CFLAGS) -c convmain.c -o convmain.o
	$(WINCC) $(CFLAGS) -c convo.c -o convo.o
	$(WINCC) $(CFLAGS) -o conv convconv.o convi.o conviso.o convlib.o convmain.o convo.o -lm

# Clean targets
clean:
	rm -rf $(OBJS)

realclean: clean
	rm -rf conv conv.exe

tidy:
	gindent $(INDENT_OPT) *.c *.h
	rm *~

# Phony targets
.PHONY: all clean realclean conv conv.exe
