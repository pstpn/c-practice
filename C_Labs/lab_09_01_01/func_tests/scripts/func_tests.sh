#!/bin/bash

# Инициализация необходимых переменных
keys=""
pos_passed="0"
neg_passed="0"
count_pos="0"
count_neg="0"


# Функция получения пути к ключам запуска
# Аргументы: 
# $1 - строка, содержащая название текстового файла (негативного или позитивного)
get_keys() {
    if [ "$i" -lt 10 ]; then
        keys="./func_tests/data/""$1""_0""$i""_args.txt"
    else
        keys="./func_tests/data/""$1""_""$i""_args.txt"
    fi
}


# Вывод результатов тестов
# $1 - строка, содержащая название текстового файла (негативного или позитивного)
# $2 - строка, содержащая имя файла, в котором расположены ключи запуска (при наличии)
testing() {
    if [ "$2" == "" ]; then
        ./func_tests/scripts/"$1"_case.sh "$in" "$out"
    else
        ./func_tests/scripts/"$1"_case.sh "$in" "$out" "$2"
    fi

    return_code="$?"

    if [ "$return_code" == "1" ]; then
        echo -e "\033[0mTEST ""$i"": \033[31mFAILED (MEMORY: ERROR)\033[31m"
    elif [ "$return_code" == "2" ]; then
        echo -e "\033[0mTEST ""$i"": \033[31mFAILED\033[31m \033[32m(MEMORY: OK)\033[32m"
        if [ "$1" == "pos" ]; then
            mem_pos_passed="$((mem_pos_passed+1))"
        else
            mem_neg_passed="$((mem_neg_passed+1))"
        fi
    elif [ "$return_code" == "3" ]; then
        echo -e "\033[0mTEST ""$i"": \033[32mPASSED\033[32m \033[31m(MEMORY: ERROR)\033[31m"
        if [ "$1" == "pos" ]; then
            pos_passed="$((pos_passed+1))"
        else
            neg_passed="$((neg_passed+1))"
        fi
    elif [ "$return_code" == "4" ]; then
        echo -e "\033[0mTEST ""$i"": \033[32mPASSED (MEMORY: OK)\033[32m"
        if [ "$1" == "pos" ]; then
            pos_passed="$((pos_passed+1))"
            mem_pos_passed="$((mem_pos_passed+1))"
        else
            neg_passed="$((neg_passed+1))"
            mem_neg_passed="$((mem_neg_passed+1))"
        fi
    elif [ "$return_code" == "5" ]; then
        echo -e "\033[0mTEST ""$i"": \033[31mFAILED\033[31m"
    else
        echo -e "\033[0mTEST ""$i"": \033[32mPASSED\033[32m"
        if [ "$1" == "pos" ]; then
            pos_passed="$((pos_passed+1))"
        else
            neg_passed="$((neg_passed+1))"
        fi
    fi
}


# Вызов функции тестирования
# Аргументы: 
# $1 - строка, содержащая название текстового файла (негативного или позитивного)
# $2 - строка, содержащая имя файла, в котором расположены ключи запуска (при наличии)
check_out_and_print() {
    if [ "$1" == "neg" ]; then
        out="$2"
    fi

    if [ "$2" != "" ]; then
        testing "$1" "$2"
    else
        testing "$1" ""
    fi
}


# Основная программа для реализации функционального тестирования
# Аргументы: 
# $1 - строка, содержащая название текстового файла (негативного или позитивного)
passing_tests() {
    i="1"

    while [ -e "./func_tests/data/""$1""_""$i""_in.txt" ] || [ -e "./func_tests/data/""$1""_0""$i""_in.txt" ]; do
        if [ "$1" == "pos" ]; then
            count_pos="$((count_pos+1))"
        else
            count_neg="$((count_neg+1))"
        fi
        if [ "$i" -lt 10 ]; then
            in="./func_tests/data/""$1""_0""$i""_in.txt"
            out="./func_tests/data/""$1""_0""$i""_out.txt"
        else
            in="./func_tests/data/""$1""_""$i""_in.txt"
            out="./func_tests/data/""$1""_""$i""_out.txt"
        fi

        get_keys "$1"
        
        if [ -e "$keys" ]; then
            check_out_and_print "$1" "$keys"
        else
            check_out_and_print "$1" ""
        fi

        i=$((i+1))
    done
}

# Инициализация счетчиков пройденных тестов памяти, если поднят флаг "USE_VALGRIND"
if [ "$USE_VALGRIND" != "" ]; then
    mem_pos_passed="0"
    mem_neg_passed="0"
fi

# Вывод количества пройденных позитивных тестов
echo -e "\n\033[32m\033[1mPositive tests:\033[1m\033[32m\n"
passing_tests "pos"
echo -e "\n\033[0mcorrect ""$pos_passed"" in ""$count_pos\033[0m"

# Вывод количества пройденных негативных тестов
echo -e "\n\033[31m\033[1mNegative tests:\033[1m\033[31m\n"
passing_tests "neg" 
echo -e "\n\033[0mcorrect ""$neg_passed"" in ""$count_neg\033[0m""\n"

# Вывод количества пройденных тестов памяти
if [ "$USE_VALGRIND" != "" ]; then
    echo -e "\033[32m\033[1mMemory passed:\033[1m\033[32m\n"
    echo -e "\033[0mPositive: ""$mem_pos_passed"" in ""$count_pos\033[0m""\n"
    echo -e "\033[0mNegative: ""$mem_neg_passed"" in ""$count_neg\033[0m""\n"
fi

# Проверка на успешность пройденных тестов
if [ "$((pos_passed+neg_passed))" == "$((count_pos+count_neg))" ]; then
    exit 0
else
    exit 1
fi
