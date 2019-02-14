CC := gcc
SRC := src
OBJ := obj
LIB := lib
INCLUDE := include

LIB_NAME := libbasicmath.a

SRC_FILES := $(wildcard $(SRC)/*.c)
OBJ_FILES := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRC_FILES))

LFLAGS := -I ./$(INCLUDE) -L ./$(LIB)
LDFLAGS := -lbasicmath

TARGET := main

$(TARGET): static-lib
	$(CC) -c  $(TARGET).c -o $(TARGET).o $(LFLAGS)
	# method 1 - include .a static lib directly
	# $(CC) $(TARGET).o $(LIB)/$(LIB_NAME) -o $(TARGET) 
	# method 2 - point to include and link location/s, and specify to use static library
	$(CC) $(TARGET).o -o $(TARGET) $(LFLAGS) $(LDFLAGS)

static-lib: objects library

objects: $(OBJ_FILES)
$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -c $< -o $@

library:
	ar rs $(LIB)/$(LIB_NAME) $(OBJ)/*.o

clean:
	rm -rf $(TARGET).o $(TARGET).exe $(OBJ)/*.o $(LIB)/*.a