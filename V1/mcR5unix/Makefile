XTRA = Makefile ../Mcman.pdf ../Mcman.txt ../README.md

MDIR = mcmlcode
CDIR = convcode

all: mcml_v1 conv_v1

exe: mcml_v1.exe conv_v1.exe

mcml_v1:
	cd $(MDIR) && make mcml_v1
	cp $(MDIR)/mcml_v1 .

conv_v1:
	cd $(CDIR) && make conv_v1
	cp $(CDIR)/conv_v1 .

mcml_v1.exe:
	cd $(MDIR) && make mcml_v1.exe
	cp $(MDIR)/mcml_v1.exe .

conv_v1.exe:
	cd $(CDIR) && make conv_v1.exe
	cp $(CDIR)/conv_v1.exe .

test:
	cd $(MDIR) && make test

dist:
	mkdir -p               mcR5unix-src-$(VERSION)
	cp $(XTRA)             mcR5unix-src-$(VERSION)
	mkdir -p               mcR5unix-src-$(VERSION)/convcode
	cp -r $(CDIR)/*.c      mcR5unix-src-$(VERSION)/convcode
	cp -r $(CDIR)/*.h      mcR5unix-src-$(VERSION)/convcode
	cp -r $(CDIR)/*.mco    mcR5unix-src-$(VERSION)/convcode
	cp -r $(CDIR)/Makefile mcR5unix-src-$(VERSION)/convcode
	mkdir -p               mcR5unix-src-$(VERSION)/mcmlcode
	cp -r $(MDIR)/*.c      mcR5unix-src-$(VERSION)/mcmlcode
	cp -r $(MDIR)/*.h      mcR5unix-src-$(VERSION)/mcmlcode
	cp -r $(MDIR)/*.mci    mcR5unix-src-$(VERSION)/mcmlcode
	cp -r $(MDIR)/Makefile mcR5unix-src-$(VERSION)/mcmlcode
	zip -r mcR5unix-src-$(VERSION) mcR5unix-src-$(VERSION)
	rm -rf mcR5unix-src-$(VERSION)

windist: conv_v1.exe mcml_v1.exe
	mkdir -p               mcR5unix-win-binary-$(VERSION)
	cp $(XTRA)             mcR5unix-win-binary-$(VERSION)
	cp mcml_v1.exe         mcR5unix-win-binary-$(VERSION)
	cp conv_v1.exe         mcR5unix-win-binary-$(VERSION)
	zip -r mcR5unix-win-binary-$(VERSION) mcR5unix-win-binary-$(VERSION)
	rm -rf mcR5unix-win-binary-$(VERSION)

# Clean targets
clean:
	cd $(MDIR) && make clean
	cd $(CDIR) && make clean

realclean: clean
	rm -rf mcml_v1 mcml_v1.exe conv_v1 conv_v1.exe test1.mco

# Phony targets
.PHONY: all clean realclean exe test
