CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic -g
PROGRAM = cesarean-cypher
BUILD_DIR = build
BIN_DIR = $(BUILD_DIR)/bin
OBJ_DIR = $(BUILD_DIR)/obj

# Target for building the final program
$(BIN_DIR)/$(PROGRAM): $(OBJ_DIR)/main.o
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Rule for compiling object files
$(OBJ_DIR)/main.o: main.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Phony target for cleaning up build artifacts
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

# Default target
all: $(BIN_DIR)/$(PROGRAM) run

# Build target
build: $(BIN_DIR)/$(PROGRAM)

# Phony target to run the program
.PHONY: run
run: $(BIN_DIR)/$(PROGRAM)
	./$(BIN_DIR)/$(PROGRAM)
