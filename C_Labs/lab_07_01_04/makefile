CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla
C_FOLDER := ./src/
INC_FOLDER := ./inc/
OBJ_FOLDER := ./out/
UNIT_FOLDER := ./unit_tests/
UNIT_FILES := $(OBJ_FOLDER)check_key.o $(OBJ_FOLDER)w_w_arr.o $(OBJ_FOLDER)tools.o $(OBJ_FOLDER)check_mysort.o $(OBJ_FOLDER)check_main.o

app.exe : $(OBJ_FOLDER)main.o $(OBJ_FOLDER)w_w_arr.o $(OBJ_FOLDER)in_out.o $(OBJ_FOLDER)tools.o
	$(CC) -o $@ $^
	
debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

$(OBJ_FOLDER)main.o : $(C_FOLDER)main.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_FOLDER)w_w_arr.o : $(C_FOLDER)w_w_arr.c $(INC_FOLDER)w_w_arr.h $(INC_FOLDER)tools.h $(INC_FOLDER)my_err.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_FOLDER)in_out.o : $(C_FOLDER)in_out.c $(INC_FOLDER)in_out.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_FOLDER)tools.o : $(C_FOLDER)tools.c $(INC_FOLDER)tools.h $(INC_FOLDER)my_err.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean release debug func unit
clean : 
	- rm *.exe *.txt

func :
	- ./func_tests/scripts/func_tests.sh

unit : unit_tests.exe
	./$<

unit_tests.exe : $(UNIT_FILES)
	$(CC) -o $@ $^ -lcheck -lpthread -lrt -lm -lsubunit

$(OBJ_FOLDER)check_main.o : $(UNIT_FOLDER)check_main.c $(INC_FOLDER)check_main.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_FOLDER)check_key.o : $(UNIT_FOLDER)check_key.c $(INC_FOLDER)check_main.h
	$(CC) $(CFLAGS) -c $< -o $@

 $(OBJ_FOLDER)check_mysort.o :  $(UNIT_FOLDER)check_mysort.c $(INC_FOLDER)check_main.h
	$(CC) $(CFLAGS) -c $< -o $@