CC := gcc
EXT := c
OBJ := objects
SRC := sources

CFLAGS := -fsanitize=address

TARGET 	:= main

SOURCES := $(shell find $(SRC) -name '*.$(EXT)')
OBJECTS := $(patsubst $(SRC)/%, $(OBJ)/%, $(SOURCES:%.$(EXT)=%.o))
OBJDIRS	:=	$(dir $(OBJECTS))
TMP		:=	$(shell mkdir --parents $(OBJDIRS))

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(CFLAGS)

$(OBJ)/%.o: $(SRC)/%.$(EXT)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	find $(OBJ) -name "*.o" -type f -delete
	rm -f $(TARGET)

check: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)
