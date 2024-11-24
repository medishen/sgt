CC = gcc
CFLAGS = -Wall -g -Iincludes
LDFLAGS =
SRC_DIR = src
OBJ_DIR = obj
EXEC = sgt
INSTALL_DIR = /usr/local/bin

SRC_FILES := $(wildcard $(SRC_DIR)/**/*.c $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(EXEC)
# Ensure object files are compiled
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@) 
	$(CC) $(CFLAGS) -c $< -o $@
# Link all object files into the final executable
$(EXEC): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(EXEC) $(LDFLAGS)
# Install the executable to the system's PATH
install: $(EXEC)
	cp $(EXEC) $(INSTALL_DIR)
	chmod +x $(INSTALL_DIR)/$(EXEC)
	echo "$(EXEC) has been installed to $(INSTALL_DIR)"

clean:
	rm -rf $(OBJ_DIR) $(EXEC)

rebuild: clean all

.PHONY: all clean rebuild install
