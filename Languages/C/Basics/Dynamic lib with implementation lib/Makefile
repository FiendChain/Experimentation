CC := g++
MAKE := make
TARGET := main

CXXFLAGS := -I '$(CURDIR)/lib' -L '$(CURDIR)/lib'
LDFLAGS := -lhello


$(TARGET): subdirs
	$(CC) src/main.o -o $@ $(CXXFLAGS) $(LDFLAGS)
	cp lib/libhello.dll libhello.dll

subdirs:
	$(MAKE) -C lib
	$(MAKE) -C src CXXFLAGS="$(CXXFLAGS)" LDFLAGS="$(LDFLAGS)"

clean:
	$(MAKE) -C lib clean
	$(MAKE) -C src clean 
	rm libhello.dll $(TARGET)
