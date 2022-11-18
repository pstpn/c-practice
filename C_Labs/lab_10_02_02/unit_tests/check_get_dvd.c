#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "../inc/in_out.h"
#include "../inc/operations.h"
#include "../inc/tools.h"
#include "../inc/my_def.h"
#include "../inc/mem.h"


START_TEST(test_dvd_one_elem)
{
    char op_type[OPERATION_TYPE_LEN + 1] = { '\0' };

    FILE *in = fopen("./func_tests/data/pos_13_in.txt", "r");

    node_t *top_in = NULL;

    node_t *top_out_first = init_all_list(1, 13);
    node_t *top_out_second = NULL;

    int count;


    get_type(in, op_type);

    read_pol(in, &count, &top_in);

    node_t *first_head = NULL;
    node_t *second_head = NULL;


    get_dvd(top_in, &first_head, &second_head, count);

    int rc = cmp_lists(first_head, top_out_first);
    

    ck_assert_int_eq(rc, TRUE);

    rc = cmp_lists(second_head, top_out_second);
    
    ck_assert_int_eq(rc, TRUE);

    free_list(top_in);
    free_list(first_head);
    free_list(second_head);
    free_list(top_out_first);
    free_list(top_out_second);
    fclose(in);
}
END_TEST


START_TEST(test_dvd_some_elems)
{
    char op_type[OPERATION_TYPE_LEN + 1] = { '\0' };

    FILE *in = fopen("./func_tests/data/pos_14_in.txt", "r");

    node_t *top_in = NULL;

    node_t *top_out_first = init_all_list(2, 5, 3);
    node_t *top_out_second = init_all_list(1, 10);

    int count;


    get_type(in, op_type);

    read_pol(in, &count, &top_in);

    node_t *first_head = NULL;
    node_t *second_head = NULL;


    get_dvd(top_in, &first_head, &second_head, count);

    int rc = cmp_lists(first_head, top_out_first);
    

    ck_assert_int_eq(rc, TRUE);

    rc = cmp_lists(second_head, top_out_second);
    
    ck_assert_int_eq(rc, TRUE);

    free_list(top_in);
    free_list(first_head);
    free_list(second_head);
    free_list(top_out_first);
    free_list(top_out_second);
    fclose(in);
}
END_TEST


Suite *get_dvd_suite(void)
{
    Suite *s = suite_create("get_dvd_tests");

    TCase *tc_pos;

    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_dvd_one_elem);
    tcase_add_test(tc_pos, test_dvd_some_elems);

    suite_add_tcase(s, tc_pos);

    return s;
}
