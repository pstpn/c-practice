CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla
# OBJS := 

app.exe : main.o
	$(CC) -o app.exe main.o
	
debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

.PHONY : clean release debug
clean : 
	rm *.o *.exe