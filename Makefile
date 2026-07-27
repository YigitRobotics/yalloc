# Compiler
CC := gcc

# Flags
CFLAGS := -Wall -Wextra -Wpedantic -O2

# Directories
OBJ_DIR := build
BIN_DIR := bin
TARGET := $(BIN_DIR)/app

# Find all .c files recursively
SRCS := $(shell find . -type f -name "*.c")

# Convert:
# ./src/main.c -> build/src/main.o
OBJS := $(patsubst ./%.c,$(OBJ_DIR)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

debug: CFLAGS += -g -O0
debug: clean all

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

valgrind: debug
	valgrind --leak-check=full ./$(TARGET)

print:
	@echo "Sources:"
	@printf "  %s\n" $(SRCS)

.PHONY: all run debug clean valgrind print