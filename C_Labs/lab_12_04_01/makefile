CC := gcc
CFLAGS := -std=c99 -Wall -Werror -I ./inc/ -lm
C_FOLDER := ./src/
SRC_FILES := $(wildcard $(C_FOLDER)*.c)
OBJ_FOLDER := ./out/
UNIT_FOLDER := ./unit_tests/
LIBS_FOLDER := ./libs/
UNIT_FILES := $(wildcard $(UNIT_FOLDER)*.c)
UNIT_FLAGS := -std=c99 -Wall -Werror -lcheck -lpthread -lrt -lsubunit -DDYNAMIC -ldl -fPIC -I ./inc/ -lm

# Libs
LIB_OBJS := $(OBJ_FOLDER)lib_arr.o

# Static lib name
STATIC_LIB_NAMES := $(LIBS_FOLDER)lib_arr.a

# Dynamic lib name
DYN_LIB_NAMES := $(LIBS_FOLDER)lib_arr.so

OBJS := $(filter-out $(LIB_OBJS),$(patsubst $(C_FOLDER)%.c,$(OBJ_FOLDER)%.o,$(SRC_FILES)))

# Static lib build (in debug mode)
Dstatic : CFLAGS += -g3
Dstatic : static

# Get app with static libs
static : OBJS += $(STATIC_LIB_NAMES)
static : $(STATIC_LIB_NAMES) app.exe

# Build static libs
$(LIBS_FOLDER)%.a : $(OBJ_FOLDER)%.o
	mkdir -p $(LIBS_FOLDER)
	ar rc $@ $<
	ranlib $@

# Get app with dynamic libs (linkage)
ld_dynamic : OBJS += $(DYN_LIB_NAMES)
ld_dynamic : CFLAGS += -fPIC
ld_dynamic : $(DYN_LIB_NAMES) app.exe

# Dynamic lib build (linkage; in debug mode)
Dld_dynamic : CFLAGS += -g3
Dld_dynamic : ld_dynamic

# Get app with dynamic libs (load)
dynamic : CFLAGS += -DDYNAMIC -ldl -fPIC
dynamic : $(DYN_LIB_NAMES)
dynamic : app.exe

# Build dynamic libs (load; in debug mode)
Ddynamic : CFLAGS += -g3
Ddynamic : dynamic

# Build dynamic libs (linkage and load)
$(LIBS_FOLDER)%.so : $(OBJ_FOLDER)%.o
	mkdir -p $(LIBS_FOLDER)
	export LD_LIBRARY_PATH=.
	$(CC) -o $@ -shared $<

# Build app
app.exe : $(OBJS) $(OBJ_FOLDER)main.o
	$(CC) $(CFLAGS) $(OBJS) -o $@

# Build *.o files
$(OBJ_FOLDER)%.o : */%.c
	mkdir -p out/
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean sunit static Dstatic sfunc ldunit ld_dynamic Dld_dynamic ldfunc dunit dynamic Ddynamic dfunc

# Func tests for app with static libs
sfunc : Dstatic
	- func_tests/scripts/func_tests.sh

# Func tests for app with dynamic libs (linkage)
ldfunc : Dld_dynamic
	- func_tests/scripts/func_tests.sh

# Func tests for app with dynamic libs (load)
dfunc : Ddynamic
	- func_tests/scripts/func_tests.sh

# Unit tests (static lib)
sunit : UNIT_OBJS :=  $(OBJ_FOLDER)check_main.o $(STATIC_LIB_NAMES) $(filter-out $(LIB_OBJS) $(OBJ_FOLDER)main.o,$(patsubst $(C_FOLDER)%.c,$(OBJ_FOLDER)%.o,$(SRC_FILES)))
sunit : $(STATIC_LIB_NAMES) $(UNIT_FILES) $(filter-out $(LIB_OBJS) $(OBJ_FOLDER)main.o,$(patsubst $(C_FOLDER)%.c,$(OBJ_FOLDER)%.o,$(SRC_FILES))) $(OBJ_FOLDER)check_main.o unit_tests.exe
	./unit_tests.exe

# Unit tests (dynamic lib; linkage)
ldunit : UNIT_OBJS :=  $(OBJ_FOLDER)check_main.o $(DYN_LIB_NAMES) $(filter-out $(LIB_OBJS) $(OBJ_FOLDER)main.o,$(patsubst $(C_FOLDER)%.c,$(OBJ_FOLDER)%.o,$(SRC_FILES)))
ldunit : $(DYN_LIB_NAMES) $(UNIT_FILES) $(filter-out $(LIB_OBJS) $(OBJ_FOLDER)main.o,$(patsubst $(C_FOLDER)%.c,$(OBJ_FOLDER)%.o,$(SRC_FILES))) $(OBJ_FOLDER)check_main.o unit_tests.exe
	./unit_tests.exe

# Unit tests (dynamic lib; load)
dunit : UNIT_OBJS :=  $(OBJ_FOLDER)check_main.o $(filter-out $(LIB_OBJS) $(OBJ_FOLDER)main.o,$(patsubst $(C_FOLDER)%.c,$(OBJ_FOLDER)%.o,$(SRC_FILES)))
dunit : $(DYN_LIB_NAMES) $(UNIT_FILES) $(filter-out $(LIB_OBJS) $(OBJ_FOLDER)main.o,$(patsubst $(C_FOLDER)%.c,$(OBJ_FOLDER)%.o,$(SRC_FILES))) $(OBJ_FOLDER)check_main.o unit_tests.exe
	./unit_tests.exe

unit_tests.exe : $(UNIT_OBJS)
	$(CC) -o $@ $(UNIT_OBJS) $(UNIT_FLAGS)

# Del trash
clean :
	- rm *.exe *.txt
	- rm -rf ./out ./libs