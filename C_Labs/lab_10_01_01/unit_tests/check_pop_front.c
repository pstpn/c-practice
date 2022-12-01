#include <stdlib.h>
#include <check.h>

#include "../inc/in_out.h"
#include "../inc/list_funcs.h"


START_TEST(test_pop_front_one_watch)
{
    FILE *in = fopen("./func_tests/data/pos_03_input.txt", "r");

    node_t *top_in = NULL;


    get_list(in, &top_in);

    free(pop_front(&top_in));

    ck_assert_ptr_null(top_in);

    free_list(top_in);
    fclose(in);
}
END_TEST


START_TEST(test_pop_front_some_watches)
{
    FILE *in = fopen("./func_tests/data/pos_07_input.txt", "r");

    node_t *top_in = NULL;


    get_list(in, &top_in);

    node_t *top_out = top_in->next;
    

    free(pop_front(&top_in));

    ck_assert_ptr_eq(top_in, top_out);

    free_list(top_in);
    fclose(in);
}
END_TEST


START_TEST(test_pop_front_zero_watches)
{
    node_t *top_in = NULL;
    node_t *top_out = NULL;
  

    free(pop_front(&top_in));

    ck_assert_ptr_eq(top_in, top_out);
}
END_TEST


Suite *pop_front_suite(void)
{
    Suite *s = suite_create("pop_front_tests");

    TCase *tc_pos;
    TCase *tc_neg;

    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_pop_front_one_watch);
    tcase_add_test(tc_pos, test_pop_front_some_watches);

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_pop_front_zero_watches);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}
