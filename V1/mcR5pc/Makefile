CC = cc
CFLAGS = -g -Wall -ansi -fno-common
WINCC = x86_64-w64-mingw32-gcc
LIBS = -lm

# Target executable
TARGET = mcml_v1 conv_v1

# Source files and corresponding object files
M_SRCS = mcmlgo.c mcmlio.c mcmlmain.c mcmlnr.c
M_OBJS = $(M_SRCS:.c=.o)

C_SRCS = convconv.c  convi.c conviso.c convmain.c convnr.c convo.c
C_OBJS = $(C_SRCS:.c=.o)

XTRA = ../Mcman.pdf ../Mcman.txt ../README.md

all: mcml_v1 conv_v1

exe: mcml_v1.exe conv_v1.exe

mcml_v1: $(M_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

conv_v1: $(C_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

mcml_v1.exe:
	$(WINCC) $(CFLAGS) -c mcmlgo.c -o mcmlgo.o 
	$(WINCC) $(CFLAGS) -c mcmlio.c -o mcmlio.o 
	$(WINCC) $(CFLAGS) -c mcmlmain.c -o mcmlmain.o 
	$(WINCC) $(CFLAGS) -c mcmlnr.c -o mcmlnr.o 
	$(WINCC) $(CFLAGS) -o $@ $(M_OBJS) $(LIBS)

conv_v1.exe:
	$(WINCC) $(CFLAGS) -c convconv.c -o convconv.o 
	$(WINCC) $(CFLAGS) -c convi.c -o convi.o 
	$(WINCC) $(CFLAGS) -c conviso.c -o conviso.o 
	$(WINCC) $(CFLAGS) -c convmain.c -o convmain.o 
	$(WINCC) $(CFLAGS) -c convnr.c -o convnr.o 
	$(WINCC) $(CFLAGS) -c convo.c -o convo.o 
	$(WINCC) $(CFLAGS) -o $@ $(C_OBJS) $(LIBS)

# dist and windist be called from parent directory because VERSION is exported from there
dist:
	mkdir -p    mcR5pc-src-$(VERSION)
	cp Makefile mcR5pc-src-$(VERSION)
	cp $(XTRA)  mcR5pc-src-$(VERSION)
	cp *.c      mcR5pc-src-$(VERSION)
	cp *.h      mcR5pc-src-$(VERSION)
	cp *.mco    mcR5pc-src-$(VERSION)
	cp *.mci    mcR5pc-src-$(VERSION)
	zip -r mcR5pc-src-$(VERSION) mcR5pc-src-$(VERSION)
	rm -rf mcR5pc-src-$(VERSION)

windist: conv_v1.exe mcml_v1.exe
	mkdir -p        mcR5pc-win-binary-$(VERSION)
	cp $(XTRA)      mcR5pc-win-binary-$(VERSION)
	cp mcml_v1.exe  mcR5pc-win-binary-$(VERSION)
	cp conv_v1.exe  mcR5pc-win-binary-$(VERSION)
	zip -r mcR5pc-win-binary-$(VERSION) mcR5pc-win-binary-$(VERSION)
	rm -rf mcR5pc-win-binary-$(VERSION)

clean:
	rm -rf $(M_OBJS)
	rm -rf $(C_OBJS)

realclean: clean
	rm -rf mcml_v1
	rm -rf mcml_v1.exe
	rm -rf conv_v1
	rm -rf conv_v1.exe
	rm -rf temp1.mco
	rm -rf temp2.mco

# Phony targets
.PHONY: all clean realclean mcml_v1.exe conv_v1.exe dist windist
