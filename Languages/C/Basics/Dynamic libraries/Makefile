CC := gcc
SRC := src
OBJ := obj
LIB := lib
INCLUDE := include

DLIB_NAME := libbasicmath.dll

SRC_FILES := $(wildcard $(SRC)/*.c)
OBJ_FILES := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRC_FILES))

LFLAGS := -I ./$(INCLUDE) -L ./$(LIB)
LDFLAGS := -lbasicmath

TARGET := main

$(TARGET): dynamic-lib
	$(CC) -c  $(TARGET).c -o $(TARGET).o $(LFLAGS)
	$(CC) $(TARGET).o -o $(TARGET) $(LFLAGS) $(LDFLAGS) # dynamic library must be in root relative to executable
	
dynamic-lib: objects
	$(CC) $(OBJ_FILES) -shared -o $(LIB)/$(DLIB_NAME)
	cp $(LIB)/$(DLIB_NAME) $(DLIB_NAME)

objects: $(OBJ_FILES)
$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -fpic -c $< -o $@ # fpic = flag: position independent code (dynamic library code is independent)

clean:
	rm -rf $(TARGET).o $(TARGET).exe $(OBJ)/*.o 

rm-dlib:
	rm -rf $(LIB)/*.dll *.dll