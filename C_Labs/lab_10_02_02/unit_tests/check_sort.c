#include <stdio.h>
#include <check.h>

#include "../inc/operations.h"
#include "../inc/tools.h"


START_TEST(test_sort_some_watches)
{
    FILE *in = fopen("./func_tests/data/pos_06_input.txt", "r");
    FILE *out = fopen("./func_tests/data/pos_06_out.txt", "r");

    node_t *top_in = NULL;
    node_t *top_out = NULL;


    get_list(in, &top_in);
    get_list(out, &top_out);

    top_in = sort(top_in, compare_int);

    int rc = cmp_watches(top_in, top_out);


    ck_assert_int_eq(rc, TRUE);

    free_list(top_in);
    free_list(top_out);
    fclose(in);
    fclose(out);
}
END_TEST


START_TEST(test_sort_one_watch)
{
    FILE *in = fopen("./func_tests/data/pos_02_input.txt", "r");
    FILE *out = fopen("./func_tests/data/pos_02_out.txt", "r");

    node_t *top_in = NULL;
    node_t *top_out = NULL;


    get_list(in, &top_in);
    get_list(out, &top_out);

    top_in = sort(top_in, compare_int);

    int rc = cmp_watches(top_in, top_out);
    

    ck_assert_int_eq(rc, TRUE);

    free_list(top_in);
    free_list(top_out);
    fclose(in);
    fclose(out);
}
END_TEST


START_TEST(test_sort_equil_watches)
{
    FILE *in = fopen("./func_tests/data/pos_04_input.txt", "r");
    FILE *out = fopen("./func_tests/data/pos_04_out.txt", "r");

    node_t *top_in = NULL;
    node_t *top_out = NULL;


    get_list(in, &top_in);
    get_list(out, &top_out);

    top_in = sort(top_in, compare_int);

    int rc = cmp_watches(top_in, top_out);


    ck_assert_int_eq(rc, TRUE);

    free_list(top_in);
    free_list(top_out);
    fclose(in);
    fclose(out);
}
END_TEST


START_TEST(test_sort_equil_fields_in_watches)
{
    FILE *in = fopen("./func_tests/data/pos_01_input.txt", "r");
    FILE *out = fopen("./func_tests/data/pos_01_out.txt", "r");

    node_t *top_in = NULL;
    node_t *top_out = NULL;


    get_list(in, &top_in);
    get_list(out, &top_out);

    top_in = sort(top_in, compare_int);

    int rc = cmp_watches(top_in, top_out);


    ck_assert_int_eq(rc, TRUE);

    free_list(top_in);
    free_list(top_out);
    fclose(in);
    fclose(out);
}
END_TEST


Suite *sort_suite(void)
{
    Suite *s = suite_create("sort_tests");

    TCase *tc_pos;

    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_sort_some_watches);
    tcase_add_test(tc_pos, test_sort_one_watch);
    tcase_add_test(tc_pos, test_sort_equil_watches);
    tcase_add_test(tc_pos, test_sort_equil_fields_in_watches);

    suite_add_tcase(s, tc_pos);

    return s;
}