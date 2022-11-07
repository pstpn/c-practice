#!/bin/bash

# Получение файлов для работы
neg_in="$1"


# Проверка на использование оболочки valgrind и запуск программы
if [ "$USE_VALGRIND" != "" ]; then
    if xargs -a "$3" valgrind --log-file=./log.txt --leak-check=full --leak-resolution=med  --quiet ./app.exe < "$neg_in" > ./neg_out.txt; then
        if [ -s ./log.txt ]; then
            exit 1
        fi
        exit 2
    elif [ -s ./log.txt ]; then
        exit 3
    else
        exit 4
    fi
else
    if xargs -a "$3" ./app.exe < "$neg_in" > ./neg_out.txt; then
        exit 5
    else
        exit 0
    fi
fi
