CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

EXECUTABLE = kruskal
BIN_FILE = kruskal.bin

.PHONY: all clean

all: $(EXECUTABLE) $(BIN_FILE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(BIN_FILE): $(SRC_FILES)
	$(CC) $(CFLAGS) -o $(BIN_FILE) $^