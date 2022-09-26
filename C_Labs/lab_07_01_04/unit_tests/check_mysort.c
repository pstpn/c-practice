#include <stdlib.h>
#include <check.h>

#include "../inc/w_w_arr.h"
#include "../inc/my_err.h"
#include "../inc/tools.h"
#include "../inc/check_main.h"


START_TEST(test_mysort_one_int_elem)
{
    int *in_arr = malloc(sizeof(int) * 4);
    init(in_arr, 1, 100);

    int *p_start = in_arr;

    mysort(p_start, 1, sizeof(int), compare_int);

    int pos_arr[] = { 100 };
    
    ck_assert_mem_eq(pos_arr, in_arr, 4);

    free(in_arr);
}
END_TEST


// START_TEST(test_mysort_one_int_elem)
// {
//     int *in_arr = malloc(sizeof(int) * 4);
//     init(in_arr, 1, 100);

//     int *p_start = in_arr;

//     mysort(p_start, 1, sizeof(int), compare_int);

//     int pos_arr[] = { 100 };
    
//     ck_assert_mem_eq(pos_arr, in_arr, 4);

//     free(in_arr);
// }
// END_TEST


Suite *mysort_suite(Suite *s)
{
    // TCase *tc_neg;
    TCase *tc_pos;

    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_mysort_one_int_elem);

    suite_add_tcase(s, tc_pos);
    
    // tc_neg = tcase_create("negatives");
    
    // // tcase_add_test(tc_neg, test_key_one_elem_found);

    // suite_add_tcase(s, tc_neg);

    return s;
}
