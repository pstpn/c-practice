#include <stdlib.h>
#include <check.h>

#include "../inc/w_w_arr.h"
#include "../inc/my_err.h"

#define EPS 1.0e-7


void init(int *arr, int size, int elem)
{
    for (int i = 0; i < size; ++i)
        *(arr++) = elem;
}


void print_arr(int *arr, int count)
{
    for (int i = 0; i < count; ++i)
        printf("%d ", arr[i]);

    printf("\n");
}


START_TEST(test_key_one_elem_found)
{
    int *in_arr = malloc(sizeof(int) * 4);
    init(in_arr, 3, 1);
    *(in_arr + 3) = 12;

    const int *p_start = in_arr;
    const int *p_end = p_start + 4;

    int *ps, *pe;
    int rc = key(p_start, p_end, &ps, &pe);

    int pos_arr[] = { 12 };
    
    ck_assert_int_eq(rc, SUCCESS);
    ck_assert_mem_eq(pos_arr, ps, 4);

    free(in_arr);
    free(ps);
}
END_TEST


START_TEST(test_key_some_elems_found)
{
    int *in_arr = malloc(sizeof(int) * 7);
    init(in_arr, 2, 3);
    init((in_arr + 2), 5, 10);

    const int *p_start = in_arr;
    const int *p_end = p_start + 7;

    int *ps, *pe;
    int rc = key(p_start, p_end, &ps, &pe);

    int pos_arr[] = { 10, 10, 10, 10, 10 };
    
    ck_assert_int_eq(rc, SUCCESS);
    ck_assert_mem_eq(pos_arr, ps, 20);

    free(in_arr);
    free(ps);
}
END_TEST


START_TEST(test_key_one_elem)
{
    int *in_arr = malloc(sizeof(int));
    init(in_arr, 1, 11);

    const int *p_start = in_arr;
    const int *p_end = p_start + 1;

    int *ps, *pe;
    int rc = key(p_start, p_end, &ps, &pe);
    
    ck_assert_int_eq(rc, INCORRECT_ARR);

    free(in_arr);
}
END_TEST


START_TEST(test_key_equil_elems)
{
    int *in_arr = malloc(sizeof(int) * 5);
    init(in_arr, 5, 99);

    const int *p_start = in_arr;
    const int *p_end = p_start + 5;

    int *ps, *pe;
    int rc = key(p_start, p_end, &ps, &pe);
    
    ck_assert_int_eq(rc, INCORRECT_ARR);

    free(in_arr);
}
END_TEST


START_TEST(test_key_all_zeros)
{
    int *in_arr = malloc(sizeof(int) * 3);
    init(in_arr, 3, 0);

    const int *p_start = in_arr;
    const int *p_end = p_start + 3;

    int *ps, *pe;
    int rc = key(p_start, p_end, &ps, &pe);
    
    ck_assert_int_eq(rc, INCORRECT_ARR);

    free(in_arr);
}
END_TEST


START_TEST(test_key_incorrect_args_new_arr)
{
    int *in_arr = malloc(sizeof(int) * 6);
    init(in_arr, 5, 3);
    init((in_arr + 3), 7, 3);

    const int *p_start = in_arr;
    const int *p_end = p_start;

    int *ps, *pe;
    int rc = key(p_start, p_end, &ps, &pe);
    
    ck_assert_int_eq(rc, INCORRECT_ARGS);

    free(in_arr);
}
END_TEST


START_TEST(test_key_null_args)
{
    int *in_arr = malloc(sizeof(int) * 6);
    init(in_arr, 5, 3);
    init((in_arr + 3), 7, 3);

    const int *p_start = in_arr;
    const int *p_end = NULL;

    int *ps, *pe;
    int rc = key(p_start, p_end, &ps, &pe);
    
    ck_assert_int_eq(rc, INCORRECT_ARGS);

    free(in_arr);
}
END_TEST


Suite* key_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;


    s = suite_create("key");
    
    tc_neg = tcase_create("negatives");
    
    tcase_add_test(tc_neg, test_key_one_elem);
    tcase_add_test(tc_neg, test_key_equil_elems);
    tcase_add_test(tc_neg, test_key_all_zeros);
    tcase_add_test(tc_neg, test_key_incorrect_args_new_arr);
    tcase_add_test(tc_neg, test_key_null_args);

    suite_add_tcase(s, tc_neg);
    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_key_one_elem_found);
    tcase_add_test(tc_pos, test_key_some_elems_found);

    suite_add_tcase(s, tc_pos);

    return s;
}


int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = key_suite();
    
    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);
    
    no_failed = srunner_ntests_failed(runner);
    
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
