# Compiler and flags
CC = cc
CFLAGS = -g -Wall -ansi -fno-common
WINCC = x86_64-w64-mingw32-gcc

# Source files and corresponding object files
M_SRCS = mcmlgo.c mcmlio.c mcmlmain.c mcmlnr.c
M_OBJS = $(M_SRCS:.c=.o)

C_SRCS = convconv.c  convi.c conviso.c convmain.c convnr.c convo.c
C_OBJS = $(C_SRCS:.c=.o)

# Libraries
LIBS = -lm

all: mcml conv

exe: mcml.exe conv.exe

mcml:
	cd MCML2.0 && make mcml
	mv MCML2.0/mcml .

conv:
	cd CONV2.0 && make conv
	mv CONV2.0/conv .

mcml.exe:
	cd MCML2.0 && make mcml.exe
	mv MCML2.0/mcml.exe .

conv.exe:
	cd CONV2.0 && make conv.exe
	mv CONV2.0/conv.exe .

# Clean targets
clean:
	cd MCML2.0 && make clean
	cd CONV2.0 && make clean

realclean: clean
	rm -rf mcml mcml.exe conv conv.exe

# Phony targets
.PHONY: all clean realclean exe
