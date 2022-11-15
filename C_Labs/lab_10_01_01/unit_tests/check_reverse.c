#include <stdlib.h>
#include <check.h>

#include "../inc/in_out.h"
#include "../inc/operations.h"
#include "../inc/mem.h"
#include "../inc/tools.h"


START_TEST(test_reverse_one_watch)
{
    FILE *in = fopen("./func_tests/data/pos_03_input.txt", "r");
    FILE *out = fopen("./func_tests/data/pos_03_out.txt", "r");

    node_t *top_in = NULL;
    node_t *top_out = NULL;


    get_list(in, &top_in);
    get_list(out, &top_out);

    top_in = reverse(top_in);

    int rc = cmp_watches(top_in, top_out);


    ck_assert_int_eq(rc, TRUE);

    free_list(top_in);
    free_list(top_out);
    fclose(in);
    fclose(out);
}
END_TEST


START_TEST(test_reverse_some_watches)
{
    FILE *in = fopen("./func_tests/data/pos_07_input.txt", "r");
    FILE *out = fopen("./func_tests/data/pos_07_out.txt", "r");

    node_t *top_in = NULL;
    node_t *top_out = NULL;


    get_list(in, &top_in);
    get_list(out, &top_out);

    top_in = reverse(top_in);

    int rc = cmp_watches(top_in, top_out);


    ck_assert_int_eq(rc, TRUE);

    free_list(top_in);
    free_list(top_out);
    fclose(in);
    fclose(out);
}
END_TEST


START_TEST(test_reverse_equil_watches)
{
    FILE *in = fopen("./func_tests/data/pos_05_input.txt", "r");
    FILE *out = fopen("./func_tests/data/pos_05_out.txt", "r");

    node_t *top_in = NULL;
    node_t *top_out = NULL;


    get_list(in, &top_in);
    get_list(out, &top_out);

    top_in = reverse(top_in);

    int rc = cmp_watches(top_in, top_out);


    ck_assert_int_eq(rc, TRUE);

    free_list(top_in);
    free_list(top_out);
    fclose(in);
    fclose(out);
}
END_TEST


Suite *reverse_suite(void)
{
    Suite *s = suite_create("reverse_tests");

    TCase *tc_pos;

    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_reverse_one_watch);
    tcase_add_test(tc_pos, test_reverse_some_watches);
    tcase_add_test(tc_pos, test_reverse_equil_watches);

    suite_add_tcase(s, tc_pos);

    return s;
}
