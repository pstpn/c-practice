#include <check.h>
#include <stdlib.h>

#include "check_my_snprintf.c"


int main(void)
{
    Suite *s = my_snprintf_suite();

    SRunner *runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    int errors = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (errors == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}