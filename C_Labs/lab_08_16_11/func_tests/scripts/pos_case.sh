#!/bin/bash

# Получение файлов для работы
pos_in="$1"
pos_out="$2"


# Проверка на использование оболочки valgrind и запуск программы
if [ "$USE_VALGRIND" != "" ]; then

    xargs -a "$3" valgrind --log-file=./log.txt --quiet ./app.exe

    # Запуск компаратора
    ./func_tests/scripts/comparator.sh "$pos_out" ./out.txt

    code_return="$?"

    if [ "$code_return" == "1" ] && [ -s ./log.txt ]; then
        exit 1
    elif [ "$code_return" == "1" ]; then
        exit 2
    elif [ -s ./log.txt ]; then
        exit 3
    else
        exit 4
    fi
else

    xargs -a "$3" ./app.exe

    # Запуск компаратора
    ./func_tests/scripts/comparator.sh "$pos_out" ./out.txt

    code_return="$?"

    if [ "$code_return" == "1" ]; then
        exit 5
    else
        exit 0
    fi
fi
