LINKER := mklink
LIB_DIR := LEDController
SRC := $(LIB_DIR)
DEST := "C:/Program Files (x86)/Arduino/libraries/$(LIB_DIR)"

link: 
	$(LINKER) /d $(DEST) "$(CURDIR)/$(SRC)"

unlink:
	rm $(DEST)

