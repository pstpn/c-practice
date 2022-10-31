#include <check.h>

#include "../inc/w_w_movies.h"
#include "../inc/w_w_mem.h"
#include "../inc/my_err.h"
#include "../inc/tools.h"


int compare_movies(movies_t *mov_1, movies_t *mov_2)
{
    if (mov_1->len != mov_2->len)
        return FALSE;

    for (int i = 0; i < mov_1->len; ++i)
    {
        if (strcmp(mov_1->movies[i].title, mov_2->movies[i].title))
            return FALSE;

        if (strcmp(mov_1->movies[i].name, mov_2->movies[i].name))
            return FALSE;

        if (mov_1->movies[i].year != mov_2->movies[i].year)
            return FALSE;
    }

    return TRUE;
}


START_TEST(test_sort_some_movies)
{
    FILE *in = fopen("./func_tests/data/pos_03_in.txt", "r");
    FILE *out = fopen("./func_tests/data/pos_03_out.txt", "r");

    movies_t m_in;
    movies_t correct;


    init_movies_arr(&m_in);
    init_movies_arr(&correct);

    read_movies_and_sort(in, &m_in, 'n');
    read_movies_and_sort(out, &correct, 'n');

    int rc = compare_movies(&m_in, &correct);


    ck_assert_int_eq(rc, TRUE);

    free_movies(&m_in);
    fclose(in);

    free_movies(&correct);
    fclose(out);
}
END_TEST


START_TEST(test_sort_one_movie)
{
    FILE *in = fopen("./func_tests/data/pos_05_in.txt", "r");
    FILE *out = fopen("./func_tests/data/pos_05_out.txt", "r");

    movies_t m_in;
    movies_t correct;


    init_movies_arr(&m_in);
    init_movies_arr(&correct);

    read_movies_and_sort(in, &m_in, 't');
    read_movies_and_sort(out, &correct, 't');

    int rc = compare_movies(&m_in, &correct);


    ck_assert_int_eq(rc, TRUE);

    free_movies(&m_in);
    fclose(in);

    free_movies(&correct);
    fclose(out);
}
END_TEST


START_TEST(test_sort_equil_movies)
{
    FILE *in = fopen("./func_tests/data/pos_07_in.txt", "r");
    FILE *out = fopen("./func_tests/data/pos_07_out.txt", "r");

    movies_t m_in;
    movies_t correct;


    init_movies_arr(&m_in);
    init_movies_arr(&correct);

    read_movies_and_sort(in, &m_in, 'n');
    read_movies_and_sort(out, &correct, 'n');

    int rc = compare_movies(&m_in, &correct);


    ck_assert_int_eq(rc, TRUE);

    free_movies(&m_in);
    fclose(in);

    free_movies(&correct);
    fclose(out);
}
END_TEST


Suite *sort_suite(void)
{
    Suite *s = suite_create("sort_tests");

    TCase *tc_pos;

    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_sort_some_movies);
    tcase_add_test(tc_pos, test_sort_one_movie);
    tcase_add_test(tc_pos, test_sort_equil_movies);

    suite_add_tcase(s, tc_pos);

    return s;
}