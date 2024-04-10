# Compiler and flags
CC = cc
CFLAGS = -g -Wall -ansi -fno-common
WINCC = x86_64-w64-mingw32-gcc
LIBS = -lm

C_SRCS = convconv.c convi.c conviso.c convmain.c convnr.c convo.c
C_OBJS = $(C_SRCS:.c=.o)

all: conv_v1

exe: conv_v1.exe

conv_v1: $(C_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

conv_v1.exe:
	$(WINCC) $(CFLAGS) -c convconv.c -o convconv.o 
	$(WINCC) $(CFLAGS) -c convi.c -o convi.o 
	$(WINCC) $(CFLAGS) -c conviso.c -o conviso.o 
	$(WINCC) $(CFLAGS) -c convmain.c -o convmain.o 
	$(WINCC) $(CFLAGS) -c convnr.c -o convnr.o 
	$(WINCC) $(CFLAGS) -c convo.c -o convo.o 
	$(WINCC) $(CFLAGS) -o $@ $(C_OBJS) $(LIBS)

clean:
	rm -rf $(C_OBJS)

realclean: clean
	rm -rf conv_v1
	rm -rf conv_v1.exe

# Phony targets
.PHONY: all clean realclean mcml_v1.exe conv_v1.exe
