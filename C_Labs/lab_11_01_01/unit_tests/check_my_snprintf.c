#include <check.h>
#include <stdio.h>

#include "../inc/my_snprintf.h"
#include "../inc/my_def.h"


START_TEST(test_my_snprintf_one_in_strs_and_some_format_str)
{
    char format[FORMAT_MAX_LEN + 1] = "Hello, %s!!! Okey.\0";

    char my_buf[BUFF_SIZE + 1] = { '\0' };
    char buf[BUFF_SIZE + 1] = { '\0' };

    char ins_str[STR_LEN + 1] = "Stepan";

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, ins_str);
    
    int count = snprintf(buf, BUFF_SIZE, format, ins_str);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


START_TEST(test_my_snprintf_many_in_strs_and_some_format_str)
{
    char format[FORMAT_MAX_LEN + 1] = "Hello, %s!!! %s Okey. %s\0";

    char my_buf[BUFF_SIZE + 1] = { '\0' };
    char buf[BUFF_SIZE + 1] = { '\0' };

    char ins_str_1[STR_LEN + 1] = "Stepan";
    char ins_str_2[STR_LEN + 1] = "Postnov";
    char ins_str_3[STR_LEN + 1] = "ICS7-31B";

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, ins_str_1, ins_str_2, ins_str_3);
    
    int count = snprintf(buf, BUFF_SIZE, format, ins_str_1, ins_str_2, ins_str_3);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


START_TEST(test_my_snprintf_empty_in_str_and_some_format_str)
{
    char format[FORMAT_MAX_LEN + 1] = "Hello, %s.\0";

    char my_buf[BUFF_SIZE + 1] = { '\0' };
    char buf[BUFF_SIZE + 1] = { '\0' };

    char ins_str[STR_LEN + 1] = "";

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, ins_str);
    
    int count = snprintf(buf, BUFF_SIZE, format, ins_str);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


START_TEST(test_my_snprintf_empty_in_str_and_only_spec_format_str)
{
    char format[FORMAT_MAX_LEN + 1] = "%s\0";

    char my_buf[BUFF_SIZE + 1] = { '\0' };
    char buf[BUFF_SIZE + 1] = { '\0' };

    char ins_str[STR_LEN + 1] = "";

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, ins_str);
    
    int count = snprintf(buf, BUFF_SIZE, format, ins_str);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


START_TEST(test_my_snprintf_empty_in_strs_and_only_spec_format_str)
{
    char format[FORMAT_MAX_LEN + 1] = "%s%s%s\0";

    char my_buf[BUFF_SIZE + 1] = { '\0' };
    char buf[BUFF_SIZE + 1] = { '\0' };

    char ins_str_1[STR_LEN + 1] = "";
    char ins_str_2[STR_LEN + 1] = "";
    char ins_str_3[STR_LEN + 1] = "";

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, ins_str_1, ins_str_2, ins_str_3);
    
    int count = snprintf(buf, BUFF_SIZE, format, ins_str_1, ins_str_2, ins_str_3);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


START_TEST(test_my_snprintf_null_buff_size)
{
    char format[FORMAT_MAX_LEN + 1] = "Hello, %s!!! Okey.\0";

    char my_buf[BUFF_SIZE + 1] = { '\0' };
    char buf[BUFF_SIZE + 1] = { '\0' };

    char ins_str[STR_LEN + 1] = "Stepan";

    int my_count = my_snprintf(my_buf, BUFF_SIZE - BUFF_SIZE, format, ins_str);
    
    int count = snprintf(buf, BUFF_SIZE - BUFF_SIZE, format, ins_str);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


START_TEST(test_my_snprintf_one_num_and_some_format_str)
{
    char format[FORMAT_MAX_LEN + 1] = "Hello, %ho!!! Okey.\0";

    char my_buf[BUFF_SIZE + 1] = { '\0' };
    char buf[BUFF_SIZE + 1] = { '\0' };

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, 5155);
    
    int count = snprintf(buf, BUFF_SIZE, format, 5155);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


START_TEST(test_my_snprintf_many_nums_and_some_format_str)
{
    char format[FORMAT_MAX_LEN + 1] = "%ho in %ho%ho\0";

    char my_buf[BUFF_SIZE + 1] = { '\0' };
    char buf[BUFF_SIZE + 1] = { '\0' };

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, 5155, 0, 737);
    
    int count = snprintf(buf, BUFF_SIZE, format, 5155, 0, 737);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


START_TEST(test_my_snprintf_negative_nums_and_some_format_str)
{
    char format[FORMAT_MAX_LEN + 1] = "%ho in %ho%ho\0";

    char my_buf[BUFF_SIZE + 1] = { '\0' };
    char buf[BUFF_SIZE + 1] = { '\0' };

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, 5155, 0, -737);
    
    int count = snprintf(buf, BUFF_SIZE, format, 5155, 0, -737);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


START_TEST(test_my_snprintf_one_num_and_only_spec_format_str)
{
    char format[FORMAT_MAX_LEN + 1] = "%ho\0";

    char my_buf[BUFF_SIZE + 1] = { '\0' };
    char buf[BUFF_SIZE + 1] = { '\0' };

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, 13);
    
    int count = snprintf(buf, BUFF_SIZE, format, 13);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


START_TEST(test_my_snprintf_many_nums_and_only_spec_format_str)
{
    char format[FORMAT_MAX_LEN + 1] = "%ho%ho%ho\0";

    char my_buf[BUFF_SIZE + 1] = { '\0' };
    char buf[BUFF_SIZE + 1] = { '\0' };

    int my_count = my_snprintf(my_buf, BUFF_SIZE, format, 13, 1, 53512);
    
    int count = snprintf(buf, BUFF_SIZE, format, 13, 1, 53512);


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


START_TEST(test_my_snprintf_format_str_without_specs)
{
    char my_buf[BUFF_SIZE + 1] = { '\0' };
    char buf[BUFF_SIZE + 1] = { '\0' };

    int my_count = my_snprintf(my_buf, BUFF_SIZE, "GGGg");
    
    int count = snprintf(buf, BUFF_SIZE, "GGGg");


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


START_TEST(test_my_snprintf_empty_format_str_without_specs)
{
    char my_buf[BUFF_SIZE + 1] = { '\0' };
    char buf[BUFF_SIZE + 1] = { '\0' };

    int my_count = my_snprintf(my_buf, BUFF_SIZE, " ");
    
    int count = snprintf(buf, BUFF_SIZE, " ");


    ck_assert_int_eq(count, my_count);
    ck_assert_str_eq(buf, my_buf);
}
END_TEST


START_TEST(test_my_snprintf_diff_specs_in_format_str)
{
    char format[FORMAT_MAX_LEN + 1] = "%ho%ho%ho  %s: %s\0";

    char my_buf[BUFF_SIZE + 1] = { '\0' };
    char buf[BUFF_SIZE + 1] = { '\0' };

    char ins_str_1[STR_LEN + 1] = "Stepan";
    char ins_str_2[STR_LEN + 1] = "Postnov";

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
    
    tcase_add_test(tc_pos, test_my_snprintf_one_in_strs_and_some_format_str);
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
