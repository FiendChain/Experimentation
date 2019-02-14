CC := g++
CXXFLAGS :=
LDFLAGS := -lfmt
TARGET := main

all: $(TARGET) lib

$(TARGET): main.o
	$(CC) $^ -o $@ $(CXXFLAGS) $(LDFLAGS)

main.o: main.cpp DLL/IDLL.h
	$(CC) -c $< -o $@ $(CXXFLAGS) $(LDFLAGS)

lib:
	$(MAKE) -C DLL

clean:
	rm -rf *.o $(TARGET)
	$(MAKE) -C DLL clean