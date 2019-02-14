CC := g++
CXXFLAGS := -fpic

TARGET := libhello

all: $(TARGET).dll

$(TARGET).dll: hello.o
	$(CC) $^ -shared -o $@ -Wl,--out-implib,$@.a

hello.o: hello.cpp hello.h
	$(CC) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -rf *.o $(TARGET).dll $(TARGET).dll.a