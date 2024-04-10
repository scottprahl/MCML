# Compiler and flags
CC = cc
CFLAGS = -g -Wall -ansi -fno-common
WINCC = x86_64-w64-mingw32-gcc
LIBS = -lm

# Source files and corresponding object files
M_SRCS = mcmlgo.c mcmlio.c mcmlmain.c mcmlnr.c
M_OBJS = $(M_SRCS:.c=.o)

all: mcml_v1

exe: mcml_v1.exe

mcml_v1: $(M_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

mcml_v1.exe:
	$(WINCC) $(CFLAGS) -c mcmlgo.c -o mcmlgo.o 
	$(WINCC) $(CFLAGS) -c mcmlio.c -o mcmlio.o 
	$(WINCC) $(CFLAGS) -c mcmlmain.c -o mcmlmain.o 
	$(WINCC) $(CFLAGS) -c mcmlnr.c -o mcmlnr.o 
	$(WINCC) $(CFLAGS) -o $@ $(M_OBJS) $(LIBS)

test:
	./mcml_v1 template.mci

clean:
	rm -rf $(M_OBJS)

realclean: clean
	rm -rf mcml_v1
	rm -rf mcml_v1.exe
	rm -rf temp1.mco
	rm -rf temp2.mco

# Phony targets
.PHONY: all clean realclean exe test
