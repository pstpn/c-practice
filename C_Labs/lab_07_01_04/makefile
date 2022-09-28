CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-conversion -Wfloat-equal -Wvla
C_FOLDER := ./src/
INC_FOLDER := ./inc/
OBJ_FOLDER := ./out/
UNIT_FOLDER := ./unit_tests/
SRC_FILES := $(wildcard $(C_FOLDER)*.c)
UNIT_FILES := $(wildcard $(UNIT_FOLDER)*.c)
OBJS := $(filter-out $(OBJ_FOLDER)main.o,$(patsubst $(C_FOLDER)%.c,$(OBJ_FOLDER)%.o,$(SRC_FILES)))


debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

app.exe : $(OBJS) $(OBJ_FOLDER)main.o
	$(CC) $^ -o $@

$(OBJ_FOLDER)%.o : */%.c $(INC_FOLDER)*.h
	mkdir -p out/
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: debug release clean func unit

func : debug
	- func_tests/scripts/func_tests.sh

unit : unit_tests.exe
	- ./unit_tests.exe
unit : OBJS := $(filter-out $(OBJ_FOLDER)check_main.o,$(patsubst $(UNIT_FOLDER)%.c,$(OBJ_FOLDER)%.o,$(UNIT_FILES)))

unit_tests.exe : $(OBJS) $(OBJ_FOLDER)check_main.o
	$(CC) $^ -o $@ -lcheck -lpthread -lrt -lm

clean :
	- rm *.txt *.exe 