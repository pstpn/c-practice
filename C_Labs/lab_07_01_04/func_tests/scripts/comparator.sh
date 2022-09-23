#!/bin/bash

# Получение файлов для работы
file_1="$1"
file_2="$2"

# Регулярное выражение для поиска действительных чисел
regex="\-?[0-9]+\.?[0-9]*"

# Найденные числа
first_digits="$(grep -Eo "$regex" "$file_1")"
second_digits="$(grep -Eo "$regex" "$file_2")"

# Сравнение ответов
if [ "$first_digits" == "$second_digits" ]; then
    exit 0
else
    exit 1
fi