# Compiler settings - "Raw C" style
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
SRC_DIR = src
OBJ_DIR = obj

# Find all C files in src/
SRCS = $(wildcard $(SRC_DIR)/*.c)
# Convert .c filenames to .o filenames
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# The final executable name
TARGET = m68k

# Default rule
all: $(TARGET)

# Link the object files into the binary
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "Build complete! Run with ./$(TARGET)"

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
