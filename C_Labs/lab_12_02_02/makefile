CC := gcc
CFLAGS := -std=c99 -Wall -Werror -I ./inc/ -lm
C_FOLDER := ./src/
OBJ_FOLDER := ./out/
LIBS_FOLDER := ./libs/

# Libs
LIB_OBJS := $(OBJ_FOLDER)lib_arr.o

# Dynamic lib name
DYN_LIB_NAMES := $(LIBS_FOLDER)lib_arr.so

# Get app with dynamic libs (load)
dynamic : CFLAGS += -DDYNAMIC -ldl -fPIC
dynamic : $(DYN_LIB_NAMES)

# Build dynamic libs (linkage and load)
$(LIBS_FOLDER)%.so : $(OBJ_FOLDER)%.o
	mkdir -p $(LIBS_FOLDER)
	export LD_LIBRARY_PATH=.
	$(CC) -o $@ -shared $<

# Build *.o files
$(OBJ_FOLDER)%.o : */%.c
	mkdir -p out/
	$(CC) $(CFLAGS) -c $< -o $@

run : dynamic
	pyuic5 ./interface/MyWindow.ui -o ./interface/MyWindow.py
	python3 ./src/main.py

.PHONY: clean dynamic run

# Del trash
clean :
	- rm -rf ./out ./libs ./interface/__pycache__