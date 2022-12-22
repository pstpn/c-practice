#include <stdlib.h>
#include <check.h>
#include <dlfcn.h>

#include "load_libs.h"
#include "lib_arr.h"
#include "my_err.h"

#ifndef DYNAMIC
int IS_DYN = 0;
key_t tmp_key = (key_t) key;
#else
int IS_DYN = 1;
key_t tmp_key = NULL;
#endif


void init(int **arr, int size, int elem)
{
    for (int i = 0; i < size; ++i)
        *((*arr)++) = elem;
}


START_TEST(test_key_one_elem)
{
    void *arr_lib = NULL;

    key_t key = tmp_key;


    if (IS_DYN)
    {
        arr_lib = dlopen("./libs/lib_arr.so", RTLD_NOW);

        key = (key_t) dlsym(arr_lib, "key");
    }

    int count = 1;
    int *in_arr = calloc(count, sizeof(int));
    init(&in_arr, count, 11);
    --in_arr;

    const int *p_start = in_arr;
    const int *p_end = p_start + 1;

    int *ps = NULL, *pe = NULL;

    int rc = key(p_start, p_end, &ps, &pe, &count);


    if (IS_DYN)
        dlclose(arr_lib);
    
    ck_assert_int_eq(rc, 0);

    free(in_arr);
}
END_TEST


START_TEST(test_key_equil_elems)
{
    void *arr_lib = NULL;

    key_t key = tmp_key;


    if (IS_DYN)
    {
        arr_lib = dlopen("./libs/lib_arr.so", RTLD_NOW);

        key = (key_t) dlsym(arr_lib, "key");
    }
    
    int count = 5;
    int *in_arr = calloc(count, sizeof(int));
    init(&in_arr, count, 99);
    in_arr -= count;

    const int *p_start = in_arr;
    const int *p_end = p_start + count;

    int *ps = NULL, *pe = NULL;
    int rc = key(p_start, p_end, &ps, &pe, &count);


    if (IS_DYN)
        dlclose(arr_lib);
    
    ck_assert_int_eq(rc, 0);

    free(in_arr);
}
END_TEST


START_TEST(test_key_all_zeros)
{
    void *arr_lib = NULL;

    key_t key = tmp_key;


    if (IS_DYN)
    {
        arr_lib = dlopen("./libs/lib_arr.so", RTLD_NOW);

        key = (key_t) dlsym(arr_lib, "key");
    }
    
    int count = 3;
    int *in_arr = calloc(count, sizeof(int));
    init(&in_arr, count, 0);
    in_arr -= count;

    const int *p_start = in_arr;
    const int *p_end = p_start + count;

    int *ps = NULL, *pe = NULL;
    int rc = key(p_start, p_end, &ps, &pe, &count);


    if (IS_DYN)
        dlclose(arr_lib);
    
    ck_assert_int_eq(rc, 0);

    free(in_arr);
}
END_TEST


START_TEST(test_key_incorrect_args_arr)
{
    void *arr_lib = NULL;

    key_t key = tmp_key;


    if (IS_DYN)
    {
        arr_lib = dlopen("./libs/lib_arr.so", RTLD_NOW);

        key = (key_t) dlsym(arr_lib, "key");
    }
    
    int count = 6;
    int *in_arr = calloc(count, sizeof(int));
    init(&in_arr, count / 2, 5);
    init(&in_arr, count / 2, 7);
    in_arr -= count;

    const int *p_start = in_arr;
    const int *p_end = p_start;

    int *ps = calloc(count, sizeof(int)), *pe = NULL;
    int rc = key(p_start, p_end, &ps, &pe, &count);

    free(in_arr);
    free(ps);

    if (IS_DYN)
        dlclose(arr_lib);
    
    ck_assert_int_eq(rc, INCORRECT_ARGS);
}
END_TEST


START_TEST(test_key_null_args)
{
    void *arr_lib = NULL;

    key_t key = tmp_key;


    if (IS_DYN)
    {
        arr_lib = dlopen("./libs/lib_arr.so", RTLD_NOW);

        key = (key_t) dlsym(arr_lib, "key");
    }
    
    int count = 6;
    int *in_arr = calloc(count, sizeof(int));
    init(&in_arr, count / 2, 5);
    init(&in_arr, count / 2, 7);
    in_arr -= count;

    const int *p_start = in_arr;
    const int *p_end = NULL;

    int *ps = calloc(count, sizeof(int)), *pe = NULL;
    int rc = key(p_start, p_end, &ps, &pe, &count);

    free(in_arr);
    free(ps);

    if (IS_DYN)
        dlclose(arr_lib);
    
    ck_assert_int_eq(rc, INCORRECT_ARGS);
}
END_TEST


START_TEST(test_key_eq_ptrs)
{
    void *arr_lib = NULL;

    key_t key = tmp_key;


    if (IS_DYN)
    {
        arr_lib = dlopen("./libs/lib_arr.so", RTLD_NOW);

        key = (key_t) dlsym(arr_lib, "key");
    }
    
    int count = 6;
    int *in_arr = calloc(count, sizeof(int));
    init(&in_arr, count / 2, 5);
    init(&in_arr, count / 2, 7);
    in_arr -= count;

    const int *p_start = in_arr;
    const int *p_end = p_start + count;

    int *ps = in_arr, *pe = NULL;
    int rc = key(p_start, p_end, &ps, &pe, &count);

    free(in_arr);

    if (IS_DYN)
        dlclose(arr_lib);
    
    ck_assert_int_eq(rc, INCORRECT_ARGS);
}
END_TEST


START_TEST(test_key_one_elem_found)
{
    void *arr_lib = NULL;

    key_t key = tmp_key;


    if (IS_DYN)
    {
        arr_lib = dlopen("./libs/lib_arr.so", RTLD_NOW);

        key = (key_t) dlsym(arr_lib, "key");
    }
    
    int count = 4;
    int *in_arr = calloc(count, sizeof(int));
    init(&in_arr, count - 1, 1);
    *in_arr = 12;
    in_arr -= count - 1;

    const int *p_start = in_arr;
    const int *p_end = p_start + count;


    count -= 3;

    int *ps = calloc(count, sizeof(int)), *pe = NULL;
    int rc = key(p_start, p_end, &ps, &pe, &count);

    int pos_arr[] = { 12 };
    

    if (IS_DYN)
        dlclose(arr_lib);

    ck_assert_int_eq(rc, SUCCESS);
    ck_assert_mem_eq(pos_arr, ps, sizeof(int));

    free(in_arr);
    free(ps);
}
END_TEST


START_TEST(test_key_some_elems_found)
{
    void *arr_lib = NULL;

    key_t key = tmp_key;


    if (IS_DYN)
    {
        arr_lib = dlopen("./libs/lib_arr.so", RTLD_NOW);

        key = (key_t) dlsym(arr_lib, "key");
    }
    
    int count = 7;
    int *in_arr = calloc(count, sizeof(int));
    init(&in_arr, count - 5, 3);
    init(&in_arr, count - 2, 10);
    in_arr -= count;

    const int *p_start = in_arr;
    const int *p_end = p_start + count;


    count -= 2;

    int *ps = calloc(count, sizeof(int)), *pe = NULL;
    int rc = key(p_start, p_end, &ps, &pe, &count);

    int pos_arr[] = { 10, 10, 10, 10, 10 };
    

    if (IS_DYN)
        dlclose(arr_lib);

    ck_assert_int_eq(rc, SUCCESS);
    ck_assert_mem_eq(pos_arr, ps, sizeof(int) * count);

    free(in_arr);
    free(ps);
}
END_TEST


Suite *key_suite(void)
{
    Suite *s = suite_create("key_tests");

    TCase *tc_neg;
    TCase *tc_pos;

    
    tc_neg = tcase_create("negatives");
    
    tcase_add_test(tc_neg, test_key_one_elem);
    tcase_add_test(tc_neg, test_key_equil_elems);
    tcase_add_test(tc_neg, test_key_all_zeros);
    tcase_add_test(tc_neg, test_key_incorrect_args_arr);
    tcase_add_test(tc_neg, test_key_null_args);
    tcase_add_test(tc_neg, test_key_eq_ptrs);

    suite_add_tcase(s, tc_neg);
    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_key_one_elem_found);
    tcase_add_test(tc_pos, test_key_some_elems_found);

    suite_add_tcase(s, tc_pos);

    return s;
}
