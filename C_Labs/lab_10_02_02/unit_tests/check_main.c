#include <check.h>

#include "check_get_val.c"
#include "check_get_ddx.c"
#include "check_get_sum.c"
#include "check_get_dvd.c"


int main(void)
{
    Suite *s = get_val_suite();

    SRunner *runner = srunner_create(s);
    s = get_ddx_suite();

    srunner_add_suite(runner, s);

    s = get_sum_suite();

    srunner_add_suite(runner, s);

    s = get_dvd_suite();

    srunner_add_suite(runner, s);

    srunner_run_all(runner, CK_VERBOSE);

    int errors = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (errors == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}