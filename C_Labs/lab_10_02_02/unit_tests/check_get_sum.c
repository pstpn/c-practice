#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "../inc/in_out.h"
#include "../inc/operations.h"
#include "../inc/tools.h"
#include "../inc/my_def.h"
#include "../inc/mem.h"


START_TEST(test_sum_one_elem)
{
    char op_type[OPERATION_TYPE_LEN + 1] = { '\0' };

    FILE *in = fopen("./func_tests/data/pos_08_in.txt", "r");

    node_t *top_out = init_all_list(1, 7);
    
    node_t *first_head = NULL;
    node_t *second_head = NULL;

    int first_count;
    int second_count;


    get_type(in, op_type);

    read_pol(in, &first_count, &first_head);
    read_pol(in, &second_count, &second_head);

    node_t *sum_head = NULL;


    get_sum(first_head, second_head, &sum_head, first_count, second_count);

    int rc = cmp_lists(sum_head, top_out);


    ck_assert_int_eq(rc, TRUE);

    free_list(sum_head);
    free_list(first_head);
    free_list(second_head);
    free_list(top_out);
    fclose(in);
}
END_TEST


START_TEST(test_sum_all_zero_elems)
{
    char op_type[OPERATION_TYPE_LEN + 1] = { '\0' };

    FILE *in = fopen("./func_tests/data/pos_09_in.txt", "r");

    node_t *top_out = init_all_list(3, 0, 0, 0);
    
    node_t *first_head = NULL;
    node_t *second_head = NULL;

    int first_count;
    int second_count;


    get_type(in, op_type);

    read_pol(in, &first_count, &first_head);
    read_pol(in, &second_count, &second_head);

    node_t *sum_head = NULL;


    get_sum(first_head, second_head, &sum_head, first_count, second_count);

    int rc = cmp_lists(sum_head, top_out);


    ck_assert_int_eq(rc, TRUE);

    free_list(sum_head);
    free_list(first_head);
    free_list(second_head);
    free_list(top_out);
    fclose(in);
}
END_TEST


START_TEST(test_sum_some_elems)
{
    char op_type[OPERATION_TYPE_LEN + 1] = { '\0' };

    FILE *in = fopen("./func_tests/data/pos_10_in.txt", "r");

    node_t *top_out = init_all_list(3, 4, 17, 2);
    
    node_t *first_head = NULL;
    node_t *second_head = NULL;

    int first_count;
    int second_count;


    get_type(in, op_type);

    read_pol(in, &first_count, &first_head);
    read_pol(in, &second_count, &second_head);

    node_t *sum_head = NULL;


    get_sum(first_head, second_head, &sum_head, first_count, second_count);

    int rc = cmp_lists(sum_head, top_out);


    ck_assert_int_eq(rc, TRUE);

    free_list(sum_head);
    free_list(first_head);
    free_list(second_head);
    free_list(top_out);
    fclose(in);
}
END_TEST


START_TEST(test_sum_equil_degrees)
{
    char op_type[OPERATION_TYPE_LEN + 1] = { '\0' };

    FILE *in = fopen("./func_tests/data/pos_11_in.txt", "r");

    node_t *top_out = init_all_list(2, 11, 6);
    
    node_t *first_head = NULL;
    node_t *second_head = NULL;

    int first_count;
    int second_count;


    get_type(in, op_type);

    read_pol(in, &first_count, &first_head);
    read_pol(in, &second_count, &second_head);

    node_t *sum_head = NULL;


    get_sum(first_head, second_head, &sum_head, first_count, second_count);

    int rc = cmp_lists(sum_head, top_out);


    ck_assert_int_eq(rc, TRUE);

    free_list(sum_head);
    free_list(first_head);
    free_list(second_head);
    free_list(top_out);
    fclose(in);
}
END_TEST


START_TEST(test_sum_non_equil_degrees)
{
    char op_type[OPERATION_TYPE_LEN + 1] = { '\0' };

    FILE *in = fopen("./func_tests/data/pos_12_in.txt", "r");

    node_t *top_out = init_all_list(4, 5, 9, 4, 10);
    
    node_t *first_head = NULL;
    node_t *second_head = NULL;

    int first_count;
    int second_count;


    get_type(in, op_type);

    read_pol(in, &first_count, &first_head);
    read_pol(in, &second_count, &second_head);

    node_t *sum_head = NULL;


    get_sum(first_head, second_head, &sum_head, first_count, second_count);

    int rc = cmp_lists(sum_head, top_out);


    ck_assert_int_eq(rc, TRUE);

    free_list(sum_head);
    free_list(first_head);
    free_list(second_head);
    free_list(top_out);
    fclose(in);
}
END_TEST


Suite *get_sum_suite(void)
{
    Suite *s = suite_create("get_sum_tests");

    TCase *tc_pos;

    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_sum_one_elem);
    tcase_add_test(tc_pos, test_sum_all_zero_elems);
    tcase_add_test(tc_pos, test_sum_some_elems);
    tcase_add_test(tc_pos, test_sum_equil_degrees);
    tcase_add_test(tc_pos, test_sum_non_equil_degrees);

    suite_add_tcase(s, tc_pos);

    return s;
}
