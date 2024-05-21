# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Iinclude

# Source files
SRC = $(wildcard src/*.c)

# Output directory
BIN_DIR = bin

# Output executable
TARGET = $(BIN_DIR)/hello

# Build target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Clean target
clean:
	rm -f $(TARGET)
