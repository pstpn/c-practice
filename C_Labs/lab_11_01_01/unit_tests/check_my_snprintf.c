#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_snprintf.h"
#include "my_def.h"


/**
 * @brief Одна строка для вставки (динамический буфер)
 * 
 */
START_TEST(test_my_snprintf_one_in_strs_and_some_dynamic_format_str)
{
    char *format = "Hello, %s!!! Okey.\0";

    char *my_buf = malloc(STR_LEN);
    char *buf = malloc(STR_LEN);

    char *ins_str = "Stepan";

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, ins_str);
    
    int count = snprintf(buf, BUFF_SIZE, format, ins_str);

    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);

    free(my_buf);
    free(buf);
}
END_TEST


/**
 * @brief Одна строка для вставки (динамическая)
 * 
 */
START_TEST(test_my_snprintf_one_in_dynamic_strs_and_some_format_str)
{
    char *format = "Hello, %s!!! Okey.\0";

    char *my_buf = malloc(STR_LEN);
    char *buf = malloc(STR_LEN);

    char *ins_str = malloc(5);


    ins_str[0] = 'r';
    ins_str[1] = 't';
    ins_str[2] = 'y';
    ins_str[3] = 'u';
    ins_str[4] = '\0';

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, ins_str);
    
    int count = snprintf(buf, BUFF_SIZE, format, ins_str);

    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);

    free(my_buf);
    free(ins_str);
    free(buf);
}
END_TEST


/**
 * @brief Три строки для вставки
 * 
 */
START_TEST(test_my_snprintf_many_in_strs_and_some_format_str)
{
    char *format = "Hello, %s!!! %s Okey. %s\0";

    char my_buf[STR_LEN + 1];
    char buf[STR_LEN + 1];

    char *ins_str_1 = "Stepan";
    char *ins_str_2 = "Postnov";
    char *ins_str_3 = "ICS7-31B";

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, ins_str_1, ins_str_2, ins_str_3);
    
    int count = snprintf(buf, BUFF_SIZE, format, ins_str_1, ins_str_2, ins_str_3);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


/**
 * @brief Пустая строка длоя вставки
 * 
 */
START_TEST(test_my_snprintf_empty_in_str_and_some_format_str)
{
    char *format = "Hello, %s.\0";

    char my_buf[STR_LEN + 1];
    char buf[STR_LEN + 1];

    char *ins_str = "";

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, ins_str);
    
    int count = snprintf(buf, BUFF_SIZE, format, ins_str);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


/**
 * @brief Пустая строка для вставки в форматную строку,
 * состояшую только из формата
 * 
 */
START_TEST(test_my_snprintf_empty_in_str_and_only_spec_format_str)
{
    char *format = "%s\0";

    char my_buf[STR_LEN + 1];
    char buf[STR_LEN + 1];

    char *ins_str = "";

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, ins_str);
    
    int count = snprintf(buf, BUFF_SIZE, format, ins_str);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


/**
 * @brief Три строки пустых строки для
 * вставки в форматную строку, состоящую 
 * только из форматов
 * 
 */
START_TEST(test_my_snprintf_empty_in_strs_and_only_spec_format_str)
{
    char *format = "%s%s%s\0";

    char my_buf[STR_LEN + 1];
    char buf[STR_LEN + 1];

    char *ins_str_1 = "";
    char *ins_str_2 = "";
    char *ins_str_3 = "";

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, ins_str_1, ins_str_2, ins_str_3);
    
    int count = snprintf(buf, BUFF_SIZE, format, ins_str_1, ins_str_2, ins_str_3);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


/**
 * @brief Тест функций с нулевым размером буфера
 * 
 */
START_TEST(test_my_snprintf_null_buff_size)
{
    char *format = "Hello, %s!!! Okey.\0";

    char my_buf[STR_LEN + 1];
    char buf[STR_LEN + 1];

    char *ins_str = "Stepan";

    int my_count = my_snprintf(my_buf, BUFF_SIZE - BUFF_SIZE, format, ins_str);
    
    int count = snprintf(buf, BUFF_SIZE - BUFF_SIZE, format, ins_str);


    ck_assert_int_eq(count, my_count);
}
END_TEST


/**
 * @brief Вставка одно числа в строку
 * 
 */
START_TEST(test_my_snprintf_one_num_and_some_format_str)
{
    char *format = "Hello, %ho!!! Okey.\0";

    char my_buf[STR_LEN + 1];
    char buf[STR_LEN + 1];

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, 5155);
    
    int count = snprintf(buf, BUFF_SIZE, format, 5155);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


/**
 * @brief Вставка трех чисел в строку
 * 
 */
START_TEST(test_my_snprintf_many_nums_and_some_format_str)
{
    char *format = "%ho in %ho%ho\0";

    char my_buf[STR_LEN + 1];
    char buf[STR_LEN + 1];

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, 5155, 0, 737);
    
    int count = snprintf(buf, BUFF_SIZE, format, 5155, 0, 737);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


/**
 * @brief Вставка отрицательного числа в строку
 * 
 */
START_TEST(test_my_snprintf_negative_nums_and_some_format_str)
{
    char *format = "%ho in %ho%ho\0";

    char my_buf[STR_LEN + 1];
    char buf[STR_LEN + 1];

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, 5155, 0, -737);
    
    int count = snprintf(buf, BUFF_SIZE, format, 5155, 0, -737);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


/**
 * @brief Вставка числа в форматную строку,
 * состоящую только из формата
 * 
 */
START_TEST(test_my_snprintf_one_num_and_only_spec_format_str)
{
    char *format = "%ho\0";

    char my_buf[STR_LEN + 1];
    char buf[STR_LEN + 1];

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, 13);
    
    int count = snprintf(buf, BUFF_SIZE, format, 13);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


/**
 * @brief Вставка трех чисел в форматнюу строку,
 * состоящую только из формата
 * 
 */
START_TEST(test_my_snprintf_many_nums_and_only_spec_format_str)
{
    char *format = "%ho%ho%ho\0";

    char my_buf[STR_LEN + 1];
    char buf[STR_LEN + 1];

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, 13, 1, 53512);
    
    int count = snprintf(buf, BUFF_SIZE, format, 13, 1, 53512);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


/**
 * @brief Строка без форматов
 * 
 */
START_TEST(test_my_snprintf_format_str_without_specs)
{
    char my_buf[STR_LEN + 1];
    char buf[STR_LEN + 1];

    int my_count = my_snprintf(my_buf, BUFF_SIZE, "GGGg");
    
    int count = snprintf(buf, BUFF_SIZE, "GGGg");


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


/**
 * @brief Строка формат из пробела
 * 
 */
START_TEST(test_my_snprintf_empty_format_str_without_specs)
{
    char my_buf[STR_LEN + 1];
    char buf[STR_LEN + 1];

    int my_count = my_snprintf(my_buf, BUFF_SIZE, " ");
    
    int count = snprintf(buf, BUFF_SIZE, " ");


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


/**
 * @brief Различные форматы в строке
 * 
 */
START_TEST(test_my_snprintf_diff_specs_in_format_str)
{
    char *format = "%ho%ho%ho  %s: %s\0";

    char my_buf[STR_LEN + 1];
    char buf[STR_LEN + 1];

    char *ins_str_1 = "Stepan";
    char *ins_str_2 = "Postnov";

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, 0, 17, 521, ins_str_1, ins_str_2);
    
    int count = snprintf(buf, BUFF_SIZE, format, 0, 17, 521, ins_str_1, ins_str_2);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


Suite *my_snprintf_suite(void)
{
    Suite *s = suite_create("my_snprintf_tests");

    TCase *tc_pos;

    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_my_snprintf_one_in_strs_and_some_dynamic_format_str);
    tcase_add_test(tc_pos, test_my_snprintf_one_in_dynamic_strs_and_some_format_str);
    tcase_add_test(tc_pos, test_my_snprintf_many_in_strs_and_some_format_str);
    tcase_add_test(tc_pos, test_my_snprintf_empty_in_str_and_some_format_str);
    tcase_add_test(tc_pos, test_my_snprintf_empty_in_str_and_only_spec_format_str);
    tcase_add_test(tc_pos, test_my_snprintf_empty_in_strs_and_only_spec_format_str);
    tcase_add_test(tc_pos, test_my_snprintf_null_buff_size);
    tcase_add_test(tc_pos, test_my_snprintf_one_num_and_some_format_str);
    tcase_add_test(tc_pos, test_my_snprintf_many_nums_and_some_format_str);
    tcase_add_test(tc_pos, test_my_snprintf_negative_nums_and_some_format_str);
    tcase_add_test(tc_pos, test_my_snprintf_one_num_and_only_spec_format_str);
    tcase_add_test(tc_pos, test_my_snprintf_many_nums_and_only_spec_format_str);
    tcase_add_test(tc_pos, test_my_snprintf_format_str_without_specs);
    tcase_add_test(tc_pos, test_my_snprintf_empty_format_str_without_specs);
    tcase_add_test(tc_pos, test_my_snprintf_diff_specs_in_format_str);

    suite_add_tcase(s, tc_pos);

    return s;
}
