# Makefile for a raylib project

# Project name (generate executable with this name)
TARGET = green

all: $(TARGET)

# Compiler
CC = cc

INCLUDES = -I./include

# Source files
SRC = $(wildcard src/*.c) 

# Compiler flags
CFLAGS = $(shell pkg-config --cflags raylib)

# Linker flags
LDFLAGS = $(shell pkg-config --libs raylib)

OBJDIR= obj

# Object files
OBJ = $(SRC:src/%.c=$(OBJDIR)/%.o)

# Rule to make the executable
$(TARGET): $(OBJ)
	$(CC) $^ $(CFLAGS) $(LDFLAGS) $(INCLUDES) -o $@


$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Rule to clean files
clean:
	rm -f $(TARGET) $(OBJ)
	@rmdir $(OBJDIR) 2>/dev/null || true

.PHONY: all clean
