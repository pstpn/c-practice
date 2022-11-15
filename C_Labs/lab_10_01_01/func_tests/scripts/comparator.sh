#!/bin/bash

# Получение файлов для работы
file_1="$1"
file_2="$2"


# Сравнение ответов
if [ "$(diff "$file_1" "$file_2")" ]; then
    exit 1
else
    exit 0
fi
