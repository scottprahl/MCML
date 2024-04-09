VERSION = 2-0-1
XTRA = Makefile README.md mcManV2.pdf

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

test:
	cd MCML2.0 && make test

dist:
	mkdir -p               mcml-$(VERSION)
	cp $(XTRA)             mcml-$(VERSION)
	mkdir -p               mcml-$(VERSION)/conv2.0
	cp -r CONV2.0/*.c      mcml-$(VERSION)/conv2.0
	cp -r CONV2.0/*.h      mcml-$(VERSION)/conv2.0
	cp -r CONV2.0/*.mco    mcml-$(VERSION)/conv2.0
	cp -r CONV2.0/Makefile mcml-$(VERSION)/conv2.0
	mkdir -p               mcml-$(VERSION)/mcml2.0
	cp -r MCML2.0/*.c      mcml-$(VERSION)/mcml2.0
	cp -r MCML2.0/*.h      mcml-$(VERSION)/mcml2.0
	cp -r MCML2.0/*.mci    mcml-$(VERSION)/mcml2.0
	cp -r MCML2.0/Makefile mcml-$(VERSION)/mcml2.0
	zip -r mcml-$(VERSION) mcml-$(VERSION)
	rm -rf mcml-$(VERSION)

windist: conv.exe mcml.exe
	mkdir -p               mcml-win-$(VERSION)
	cp $(XTRA)             mcml-win-$(VERSION)
	cp mcml.exe conv.exe   mcml-win-$(VERSION)
	mkdir -p               mcml-win-$(VERSION)/conv2.0
	cp -r CONV2.0/*.c      mcml-win-$(VERSION)/conv2.0
	cp -r CONV2.0/*.h      mcml-win-$(VERSION)/conv2.0
	cp -r CONV2.0/*.mco    mcml-win-$(VERSION)/conv2.0
	cp -r CONV2.0/Makefile mcml-win-$(VERSION)/conv2.0
	mkdir -p               mcml-win-$(VERSION)/mcml2.0
	cp -r MCML2.0/*.c      mcml-win-$(VERSION)/mcml2.0
	cp -r MCML2.0/*.h      mcml-win-$(VERSION)/mcml2.0
	cp -r MCML2.0/*.mci    mcml-win-$(VERSION)/mcml2.0
	cp -r MCML2.0/Makefile mcml-win-$(VERSION)/mcml2.0
	zip -r mcml-win-$(VERSION) mcml-win-$(VERSION)
	rm -rf mcml-win-$(VERSION)

# Clean targets
clean:
	cd MCML2.0 && make clean
	cd CONV2.0 && make clean

realclean: clean
	rm -rf mcml mcml.exe conv conv.exe test1.mco

# Phony targets
.PHONY: all clean realclean exe test
