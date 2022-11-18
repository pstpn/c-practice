#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "../inc/in_out.h"
#include "../inc/operations.h"
#include "../inc/my_def.h"
#include "../inc/mem.h"


START_TEST(test_val_one_elem)
{
    char op_type[OPERATION_TYPE_LEN + 1] = { '\0' };

    FILE *in = fopen("./func_tests/data/pos_01_in.txt", "r");

    node_t *top_in = NULL;

    int a;
    int count;


    get_type(in, op_type);

    read_val(in, &count, &top_in, &a);

    int p = get_val(top_in, count, a);


    ck_assert_int_eq(p, 13);

    free_list(top_in);
    fclose(in);
}
END_TEST


START_TEST(test_val_all_zero_elems)
{
    char op_type[OPERATION_TYPE_LEN + 1] = { '\0' };

    FILE *in = fopen("./func_tests/data/pos_02_in.txt", "r");

    node_t *top_in = NULL;

    int a;
    int count;


    get_type(in, op_type);

    read_val(in, &count, &top_in, &a);

    int p = get_val(top_in, count, a);


    ck_assert_int_eq(p, 0);

    free_list(top_in);
    fclose(in);
}
END_TEST


START_TEST(test_val_zero_a)
{
    char op_type[OPERATION_TYPE_LEN + 1] = { '\0' };

    FILE *in = fopen("./func_tests/data/pos_03_in.txt", "r");

    node_t *top_in = NULL;

    int a;
    int count;


    get_type(in, op_type);

    read_val(in, &count, &top_in, &a);

    int p = get_val(top_in, count, a);


    ck_assert_int_eq(p, 1);

    free_list(top_in);
    fclose(in);
}
END_TEST


START_TEST(test_val_some_elems)
{
    char op_type[OPERATION_TYPE_LEN + 1] = { '\0' };

    FILE *in = fopen("./func_tests/data/pos_04_in.txt", "r");

    node_t *top_in = NULL;

    int a;
    int count;


    get_type(in, op_type);

    read_val(in, &count, &top_in, &a);

    int p = get_val(top_in, count, a);


    ck_assert_int_eq(p, 181);

    free_list(top_in);
    fclose(in);
}
END_TEST


Suite *get_val_suite(void)
{
    Suite *s = suite_create("get_val_tests");

    TCase *tc_pos;

    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_val_one_elem);
    tcase_add_test(tc_pos, test_val_all_zero_elems);
    tcase_add_test(tc_pos, test_val_zero_a);
    tcase_add_test(tc_pos, test_val_some_elems);

    suite_add_tcase(s, tc_pos);

    return s;
}
