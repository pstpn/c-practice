#include <check.h>

#include "../inc/w_w_arr.h"
#include "../inc/my_err.h"
#include "../inc/tools.h"


int compare_string(const void *str_1, const void *str_2)
{
    return strcmp((char *) str_1, (char *) str_2);
}


int compare_double(const void *a_1, const void *a_2)
{
    if ((*((double *) a_1) - *((double *) a_2)) > 0)
        return 1;
    else if ((*((double *) a_1) - *((double *) a_2)) < 0)
        return -1;
    
    return 0;
}


START_TEST(test_mysort_one_int_elem)
{
    int in_arr[] = { 100 };
    int *p_start = in_arr;

    mysort(p_start, 1, sizeof(int), compare_int);

    int pos_arr[] = { 100 };
    
    ck_assert_mem_eq(pos_arr, in_arr, 4);
}
END_TEST


START_TEST(test_mysort_equil_int_elems)
{
    int in_arr[] = { 100, 100, 100, 100, 100 };
    int *p_start = in_arr;

    mysort(p_start, 5, sizeof(int), compare_int);

    int pos_arr[] = { 100, 100, 100, 100, 100 };
    
    ck_assert_mem_eq(pos_arr, in_arr, 20);
}
END_TEST


START_TEST(test_mysort_sorted_int_elems)
{
    int in_arr[] = { -10, 20, 30, 40, 50 };
    int *p_start = in_arr;

    mysort(p_start, 5, sizeof(int), compare_int);

    int pos_arr[] = { -10, 20, 30, 40, 50 };
    
    ck_assert_mem_eq(pos_arr, in_arr, 20);
}
END_TEST


START_TEST(test_mysort_all_zeros_int_elems)
{
    int in_arr[] = { 0, 0, 0, 0, 0, 0, 0 };
    int *p_start = in_arr;

    mysort(p_start, 7, sizeof(int), compare_int);

    int pos_arr[] = { 0, 0, 0, 0, 0, 0, 0 };
    
    ck_assert_mem_eq(pos_arr, in_arr, 28);
}
END_TEST


START_TEST(test_mysort_common_int_elems)
{
    int in_arr[] = { 100, 1, 22, -15, 66, 3, -7 };
    int *p_start = in_arr;

    mysort(p_start, 7, sizeof(int), compare_int);

    int pos_arr[] = { -15, -7, 1, 3, 22, 66, 100 };
    
    ck_assert_mem_eq(pos_arr, in_arr, 28);
}
END_TEST


START_TEST(test_mysort_one_str_elem)
{
    char in_arr[1][4] = { "aaa" };
    char (*p_start)[4] = in_arr;

    mysort(p_start, 1, 4, compare_string);

    char pos_arr[1][4] = { "aaa" };
    
    ck_assert_mem_eq(pos_arr, in_arr, 3);
}
END_TEST


START_TEST(test_mysort_common_str_elems)
{
    char in_arr[4][4] = { "aba", "aaa", "aab", "aac" };
    char (*p_start)[4] = in_arr;

    mysort(p_start, 4, 4, compare_string);

    char pos_arr[4][4] = { "aaa", "aab", "aac", "aba" };
    
    ck_assert_mem_eq(pos_arr, in_arr, 12);
}
END_TEST


START_TEST(test_mysort_sorted_str_elems)
{
    char in_arr[4][4] = { "aaa", "aab", "bac", "aba" };
    char (*p_start)[4] = in_arr;

    mysort(p_start, 4, 4, compare_string);

    char pos_arr[4][4] = { "aaa", "aab", "aba", "bac" };
    
    ck_assert_mem_eq(pos_arr, in_arr, 16);
}
END_TEST


START_TEST(test_mysort_equil_str_elems)
{
    char in_arr[3][4] = { "aaa", "aaa", "aaa" };
    char (*p_start)[4] = in_arr;

    mysort(p_start, 3, 4, compare_string);

    char pos_arr[3][4] = { "aaa", "aaa", "aaa" };
    
    ck_assert_mem_eq(pos_arr, in_arr, 9);
}
END_TEST


START_TEST(test_mysort_empty_str_elem)
{
    char in_arr[2][1] = { "", "" };
    char (*p_start)[1] = in_arr;

    mysort(p_start, 2, 1, compare_string);

    char pos_arr[2][1] = { "", "" };
    
    ck_assert_mem_eq(pos_arr, in_arr, 2);
}
END_TEST


START_TEST(test_mysort_one_double_elem)
{
    double in_arr[] = { 100.103 };
    double *p_start = in_arr;

    mysort(p_start, 1, sizeof(double), compare_double);

    double pos_arr[] = { 100.103 };
    
    ck_assert_mem_eq(pos_arr, in_arr, 8);
}
END_TEST


START_TEST(test_mysort_common_double_elems)
{
    double in_arr[] = { 100.103, -13.444, 2.2, 0.1515 };
    double *p_start = in_arr;

    mysort(p_start, 4, sizeof(double), compare_double);

    double pos_arr[] = { -13.444, 0.1515, 2.2, 100.103 };
    
    ck_assert_mem_eq(pos_arr, in_arr, 32);
}
END_TEST


START_TEST(test_mysort_sorted_double_elems)
{
    double in_arr[] = { 14.2, 15.5, 44.03 };
    double *p_start = in_arr;

    mysort(p_start, 3, sizeof(double), compare_double);

    double pos_arr[] = { 14.2, 15.5, 44.03 };
    
    ck_assert_mem_eq(pos_arr, in_arr, 24);
}
END_TEST


START_TEST(test_mysort_all_zeros_double_elem)
{
    double in_arr[] = { 0.0, 0.0 };
    double *p_start = in_arr;

    mysort(p_start, 2, sizeof(double), compare_double);

    double pos_arr[] = { 0.0, 0.0 };
    
    ck_assert_mem_eq(pos_arr, in_arr, 16);
}
END_TEST


Suite *mysort_suite(void)
{
    Suite *s = suite_create("mysort_tests");

    TCase *tc_pos;

    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_mysort_one_int_elem);
    tcase_add_test(tc_pos, test_mysort_equil_int_elems);
    tcase_add_test(tc_pos, test_mysort_sorted_int_elems);
    tcase_add_test(tc_pos, test_mysort_all_zeros_int_elems);
    tcase_add_test(tc_pos, test_mysort_common_int_elems);
    tcase_add_test(tc_pos, test_mysort_one_str_elem);
    tcase_add_test(tc_pos, test_mysort_common_str_elems);
    tcase_add_test(tc_pos, test_mysort_sorted_str_elems);
    tcase_add_test(tc_pos, test_mysort_equil_str_elems);
    tcase_add_test(tc_pos, test_mysort_empty_str_elem);
    tcase_add_test(tc_pos, test_mysort_one_double_elem);
    tcase_add_test(tc_pos, test_mysort_common_double_elems);
    tcase_add_test(tc_pos, test_mysort_sorted_double_elems);
    tcase_add_test(tc_pos, test_mysort_all_zeros_double_elem);

    suite_add_tcase(s, tc_pos);

    return s;
}