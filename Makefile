# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Iinclude

# Source files
SRC = $(wildcard src/*.c)

# Source files excluding main.c for testing
TEST_SRC = $(filter-out src/main.c, $(SRC))

# Test files
TEST_FILES = $(wildcard tests/*.c)

# Output directory
BIN_DIR = bin

# Output executable
TARGET = $(BIN_DIR)/hello

# Test executable
TEST_TARGET = $(BIN_DIR)/test_greet

# Build target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Build test target
test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_FILES) $(TEST_SRC)
	$(CC) $(CFLAGS) -o $@ $^ -lcunit

# Clean target
clean:
	rm -f $(TARGET) $(TEST_TARGET) output.txt
