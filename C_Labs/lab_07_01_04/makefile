CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla
C_FOLDER := ./src/
INC_FOLDER := ./inc/
OBJ_FOLDER := ./out/

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

.PHONY : clean release debug func_test
clean : 
	rm *.exe *.txt

func_test:
	- ./func_tests/scripts/func_tests.sh