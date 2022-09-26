#include <stdlib.h>
#include <check.h>

#include "../inc/check_main.h"


Suite *tests_suite(void)
{
    Suite *s = suite_create("my_tests");

    s = mysort_suite(s);
    s = key_suite(s);

    return s;
}


int main(void)
{
    Suite *s = tests_suite();

    SRunner *runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    int errors = srunner_ntests_failed(runner);


    srunner_free(runner);

    return (errors == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}