#include <check.h>

#include "check_get_det.c"
#include "check_matrix_addition.c"
#include "check_product_matrix.c"


int main(void)
{
    Suite *s = get_det_suite();

    SRunner *runner = srunner_create(s);
    s = mtrx_add_suite();

    srunner_add_suite(runner, s);
    s = mtrx_prod_suite();

    srunner_add_suite(runner, s);

    srunner_run_all(runner, CK_VERBOSE);

    int errors = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (errors == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}