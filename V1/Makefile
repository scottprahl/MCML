export VERSION = 1-0-1

UNIX_DIR = mcR5unix
PC_DIR = mcR5pc

all: pc unix

unix:
	cd $(UNIX_DIR) && make dist
	cd $(UNIX_DIR) && make windist
	mv $(UNIX_DIR)/*.zip .

pc:
	cd $(PC_DIR) && make dist
	cd $(PC_DIR) && make windist
	mv $(PC_DIR)/*.zip .

# Phony targets
.PHONY: all
