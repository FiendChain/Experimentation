JC := javac
JR := appletviewer

SRC := source
BYTE := bytecode
FIND := C:/cygwin64/bin/find.exe

SRC_FILES := $(shell $(FIND) $(SRC) -name *java)
BYTE_FILES := $(patsubst $(SRC)/%.java, $(BYTE)/%.class, $(SRC_FILES))
BYTE_BINARY_DIR := $(dir $(BYTE_FILES))

main: $(BYTE_FILES)

$(BYTE)/%.class: $(SRC)/%.java
	$(JC) -classpath $(SRC) $< -d $(BYTE)

run:
	$(JR) -J-classpath -J$(BYTE) Pong.html

clean:
	rm -f $(BYTE)/*.class