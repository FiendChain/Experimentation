CC := g++
CXXFLAGS := 
LDFLAGS :=
TARGET := libdll.dll

$(TARGET): DLL.o DLLExport.o
	$(CC) $^ -shared -o $@

DLLExport.o: DLLExport.cpp DLLExport.h
	$(CC) -c $< -o $@ -fpic $(CXXFLAGS) $(LDFLAGS)

DLL.o: DLL.cpp DLL.h ../IDLL.h
	$(CC) -c $< -o $@ -fpic $(CXXFLAGS) $(LDFLAGS)

clean:
	rm -rf *.o *.map $(TARGET)