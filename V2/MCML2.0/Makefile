# Compiler and flags
CC = cc
CFLAGS = -g -Wall -ansi -fno-common
WINCC = x86_64-w64-mingw32-gcc
INDENT_OPT = -br -brs -nbs -ci4 -cli0 -bli0 -l120 -ncdb -nce -nlp -npcs -npsl -i4 -nut

# Source files and corresponding object files
M_SRCS = mcmlgo.c mcmlio.c mcmlmain.c
M_OBJS = $(M_SRCS:.c=.o)

# Libraries
LIBS = -lm

all: mcml

exe: mcml.exe

mcml:
	$(CC) $(CFLAGS) -c mcmlgo.c -o mcmlgo.o 
	$(CC) $(CFLAGS) -c mcmlio.c -o mcmlio.o 
	$(CC) $(CFLAGS) -c mcmlmain.c -o mcmlmain.o 
	$(CC) $(CFLAGS) -o $@ $(M_OBJS) $(LIBS)

mcml.exe:
	$(WINCC) $(CFLAGS) -c mcmlgo.c -o mcmlgo.o 
	$(WINCC) $(CFLAGS) -c mcmlio.c -o mcmlio.o 
	$(WINCC) $(CFLAGS) -c mcmlmain.c -o mcmlmain.o 
	$(WINCC) $(CFLAGS) -o $@ $(M_OBJS) $(LIBS)

# Clean targets
clean:
	rm -rf $(M_OBJS)
	rm -rf test1.mco

realclean: clean
	rm -rf mcml
	rm -rf mcml.exe
	rm -rf test1.mco sample1a.mco sample1b.mco sample2.mco

test: mcml
	./mcml template.mci
	./mcml sample1.mci
	./mcml sample2.mci

tidy:
	gindent $(INDENT_OPT) *.c *.h
	rm *~

# Phony targets
.PHONY: all clean realclean tidy mcml mcml.exe test
