#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "../inc/in_out.h"
#include "../inc/operations.h"
#include "../inc/tools.h"
#include "../inc/my_def.h"
#include "../inc/mem.h"


START_TEST(test_ddx_one_elem)
{
    char op_type[OPERATION_TYPE_LEN + 1] = { '\0' };

    FILE *in = fopen("./func_tests/data/pos_05_in.txt", "r");

    node_t *top_in = NULL;
    node_t *top_out = NULL;

    int count;


    get_type(in, op_type);

    read_pol(in, &count, &top_in);

    node_t *ddx_head = NULL;


    get_ddx(top_in, &ddx_head, count);

    int rc = cmp_lists(ddx_head, top_out);


    ck_assert_int_eq(rc, TRUE);

    free_list(ddx_head);
    free_list(top_in);
    fclose(in);
}
END_TEST


START_TEST(test_ddx_all_zero_elems)
{
    char op_type[OPERATION_TYPE_LEN + 1] = { '\0' };

    FILE *in = fopen("./func_tests/data/pos_06_in.txt", "r");

    node_t *top_in = NULL;
    node_t *top_out = init_all_list(2, 0, 0);

    int count;


    get_type(in, op_type);

    read_pol(in, &count, &top_in);

    node_t *ddx_head = NULL;


    get_ddx(top_in, &ddx_head, count);

    int rc = cmp_lists(ddx_head, top_out);


    ck_assert_int_eq(rc, TRUE);

    free_list(ddx_head);
    free_list(top_in);
    free_list(top_out);
    fclose(in);
}
END_TEST


START_TEST(test_ddx_some_elems)
{
    char op_type[OPERATION_TYPE_LEN + 1] = { '\0' };

    FILE *in = fopen("./func_tests/data/pos_07_in.txt", "r");

    node_t *top_in = NULL;
    node_t *top_out = init_all_list(4, 24, 6, 0, 13);

    int count;


    get_type(in, op_type);

    read_pol(in, &count, &top_in);

    node_t *ddx_head = NULL;


    get_ddx(top_in, &ddx_head, count);

    int rc = cmp_lists(ddx_head, top_out);


    ck_assert_int_eq(rc, TRUE);

    free_list(ddx_head);
    free_list(top_in);
    free_list(top_out);
    fclose(in);
}
END_TEST


Suite *get_ddx_suite(void)
{
    Suite *s = suite_create("get_ddx_tests");

    TCase *tc_pos;

    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_ddx_one_elem);
    tcase_add_test(tc_pos, test_ddx_all_zero_elems);
    tcase_add_test(tc_pos, test_ddx_some_elems);

    suite_add_tcase(s, tc_pos);

    return s;
}
