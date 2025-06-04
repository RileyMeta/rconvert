# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -O2

# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := /usr/local/bin

# Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# Output executable
TARGET := rconvert
TARGET_PATH := $(BUILD_DIR)/$(TARGET)

# Default rule
all: $(TARGET_PATH)

# Link object files to create the executable
$(TARGET_PATH): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Install binary
install: $(TARGET_PATH)
	sudo install -Dm755 $< "$(DESTDIR)$(BIN_DIR)/$(TARGET)"

# Uninstall binary
uninstall:
	sudo rm -f $(BIN_DIR)/$(TARGET)

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean install uninstall

