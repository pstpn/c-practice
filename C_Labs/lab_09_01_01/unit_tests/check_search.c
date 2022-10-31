#include <stdlib.h>
#include <check.h>

#include "../inc/w_w_movies.h"
#include "../inc/w_w_mem.h"
#include "../inc/my_err.h"


START_TEST(test_search_one_movie)
{
    FILE *in = fopen("./func_tests/data/pos_06_in.txt", "r");

    movies_t movies;

    char *key = "Toshiro Mifune";


    init_movies_arr(&movies);

    read_movies_and_sort(in, &movies, 't');

    int index = binary_search(&movies, 't', key);


    ck_assert_int_eq(index, 0);

    free_movies(&movies);
    fclose(in);
}
END_TEST


START_TEST(test_search_some_movies_and_found)
{
    FILE *in = fopen("./func_tests/data/pos_02_in.txt", "r");

    movies_t movies;

    char *key = "John Ford";


    init_movies_arr(&movies);

    read_movies_and_sort(in, &movies, 'n');

    int index = binary_search(&movies, 'n', key);


    ck_assert_int_eq(index, 1);

    free_movies(&movies);
    fclose(in);
}
END_TEST


START_TEST(test_search_title_not_found)
{
    FILE *in = fopen("./func_tests/data/pos_02_in.txt", "r");

    movies_t movies;

    char *key = "John Ford";


    init_movies_arr(&movies);

    read_movies_and_sort(in, &movies, 't');

    int index = binary_search(&movies, 't', key);


    ck_assert_int_eq(index, -1);

    free_movies(&movies);
    fclose(in);
}
END_TEST


START_TEST(test_search_name_not_found)
{
    FILE *in = fopen("./func_tests/data/pos_02_in.txt", "r");

    movies_t movies;

    char *key = "John";


    init_movies_arr(&movies);

    read_movies_and_sort(in, &movies, 'n');

    int index = binary_search(&movies, 'n', key);


    ck_assert_int_eq(index, -1);

    free_movies(&movies);
    fclose(in);
}
END_TEST


START_TEST(test_search_year_not_found)
{
    FILE *in = fopen("./func_tests/data/pos_02_in.txt", "r");

    movies_t movies;

    char *key = "22";


    init_movies_arr(&movies);

    read_movies_and_sort(in, &movies, 'y');

    int index = binary_search(&movies, 'y', key);


    ck_assert_int_eq(index, -1);

    free_movies(&movies);
    fclose(in);
}
END_TEST


Suite *search_suite(void)
{
    Suite *s = suite_create("search_tests");

    TCase *tc_pos;

    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_search_one_movie);
    tcase_add_test(tc_pos, test_search_some_movies_and_found);
    tcase_add_test(tc_pos, test_search_title_not_found);
    tcase_add_test(tc_pos, test_search_name_not_found);
    tcase_add_test(tc_pos, test_search_year_not_found);

    suite_add_tcase(s, tc_pos);

    return s;
}
