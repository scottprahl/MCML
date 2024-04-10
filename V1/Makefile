export VERSION = 1-0-1

UNIX_DIR = mcR5unix
PC_DIR = mcR5pc

all:
	cd $(UNIX_DIR) && make
	cp $(UNIX_DIR)/mcml_v1 .
	cp $(UNIX_DIR)/conv_v1 .

dists: pcdist unixdist

unixdist:
	cd $(UNIX_DIR) && make dist
	cd $(UNIX_DIR) && make windist
	mv $(UNIX_DIR)/*.zip .

pcdist:
	cd $(PC_DIR) && make dist
	cd $(PC_DIR) && make windist
	mv $(PC_DIR)/*.zip .

clean:
	cd $(UNIX_DIR) && make clean
	cd $(PC_DIR) && make clean

realclean:
	cd $(UNIX_DIR) && make realclean
	cd $(PC_DIR) && make realclean
	rm -rf mcml_v1 conv_v1

.PHONY: all dists unixdist pcdist clean realclean
