#include <check.h>

#include "check_search.c"
#include "check_sort.c"


int main(void)
{
    Suite *s = sort_suite();

    SRunner *runner = srunner_create(s);
    s = search_suite();

    srunner_add_suite(runner, s);

    srunner_run_all(runner, CK_VERBOSE);

    int errors = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (errors == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}