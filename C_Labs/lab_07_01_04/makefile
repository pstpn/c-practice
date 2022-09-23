CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla

app.exe : main.o w_w_arr.o in_out.o tools.o
	$(CC) -o $@ $^
	
debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

w_w_arr.o : w_w_arr.c w_w_arr.h tools.h my_err.h
	$(CC) $(CFLAGS) -c $<

in_out.o : in_out.c in_out.h
	$(CC) $(CFLAGS) -c $<

tools.o : tools.c tools.h my_err.h
	$(CC) $(CFLAGS) -c $<

.PHONY : clean release debug func_test
clean : 
	rm *.o *.exe *.txt

func_test:
	- ./func_tests/scripts/func_tests.sh