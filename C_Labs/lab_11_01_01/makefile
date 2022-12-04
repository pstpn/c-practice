CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-conversion -Wfloat-equal -Wvla -I ./inc/ -lm
C_FOLDER := ./src/
SRC_FILES := $(wildcard $(C_FOLDER)*.c)
OBJ_FOLDER := ./out/
UNIT_FOLDER := ./unit_tests/
UNIT_FILES := $(wildcard $(UNIT_FOLDER)*.c)
OBJS := $(filter-out $(OBJ_FOLDER)main.o,$(patsubst $(C_FOLDER)%.c,$(OBJ_FOLDER)%.o,$(SRC_FILES)))
UNIT_FLAGS := -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-conversion -Wfloat-equal -Wvla -lcheck -lpthread -lrt -I ./inc/ -lm


debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

app.exe : $(OBJS) $(OBJ_FOLDER)main.o
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_FOLDER)%.o : */%.c
	mkdir -p out/
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: debug release clean func unit

func : debug
	- func_tests/scripts/func_tests.sh

sub_unit : UNIT_FLAGS += -lsubunit
sub_unit : unit

unit : unit_tests.exe
	- ./unit_tests.exe
unit : OBJS := $(filter-out $(OBJ_FOLDER)check_main.o,$(patsubst $(UNIT_FOLDER)%.c,$(OBJ_FOLDER)%.o,$(UNIT_FILES)))

unit_tests.exe : $(OBJS) $(OBJ_FOLDER)check_main.o
	$(CC) $^ $(UNIT_FLAGS) -o $@

clean :
	- rm *.exe 
	- rm -rf ./out