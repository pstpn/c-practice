#include <check.h>

#include "../src/lib_arr.c"
#include "check_key.c"
#include "check_mysort.c"


int main(void)
{
    Suite *s = mysort_suite();

    SRunner *runner = srunner_create(s);
    s = key_suite();

    srunner_add_suite(runner, s);

    srunner_run_all(runner, CK_VERBOSE);

    int errors = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (errors == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}