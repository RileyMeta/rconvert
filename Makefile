# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Source and object files
SRCS = rconvert.c
OBJS = $(SRCS:.c=.o)

# Output executable
TARGET = rconvert

# Default rule
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean

install: $(TARGET)
	sudo install -Dm755 $(TARGET) /usr/local/bin/$(TARGET)

uninstall:
	sudo rm -f /usr/local/bin/$(TARGET)
