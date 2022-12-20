CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-conversion -Wfloat-equal -Wvla -I ./inc/ -lm
C_FOLDER := ./src/
SRC_FILES := $(wildcard $(C_FOLDER)*.c)
OBJ_FOLDER := out/
UNIT_FOLDER := ./unit_tests/
UNIT_FILES := $(wildcard $(UNIT_FOLDER)*.c)
UNIT_FLAGS := -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-conversion -Wfloat-equal -Wvla -lcheck -lpthread -lrt -I ./inc/ -lm
STATIC_LIB_OBJ := $(OBJ_FOLDER)lib_static_arr.o
STATIC_LIB_NAME := $(OBJ_FOLDER)lib_static_arr.a
OBJS := $(filter-out $(STATIC_LIB_OBJ),$(patsubst $(C_FOLDER)%.c,$(OBJ_FOLDER)%.o,$(SRC_FILES)))

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

Dstatic : CFLAGS += -g3
Dstatic : static_lib_build app.exe
Dstatic : OBJS += $(STATIC_LIB_NAME)

static : static_lib_build app.exe
static : OBJS += $(STATIC_LIB_NAME)

static_lib_build : $(STATIC_LIB_OBJ)
	ar rc $(STATIC_LIB_NAME) $(STATIC_LIB_OBJ)
	ranlib $(STATIC_LIB_NAME)

app.exe : $(OBJS) $(OBJ_FOLDER)main.o
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ_FOLDER)%.o : */%.c
	mkdir -p out/
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: debug release clean func unit static_lib_build static

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
	- rm *.exe *.txt
	- rm -rf ./out