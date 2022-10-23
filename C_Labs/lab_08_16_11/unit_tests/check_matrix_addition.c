#include <stdio.h>
#include <check.h>

#include "../inc/w_w_mem.h"


void matrix_addition(double **mtrx_1, double **mtrx_2, double **cur_mtrx, int n, int m)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cur_mtrx[i][j] = mtrx_1[i][j] + mtrx_2[i][j];
}


START_TEST(test_mtrx_add_some_matrix)
{
    double **res = allocate_matrix(2, 3);
    double **cur = allocate_matrix(2, 3);
    double **m_1 = allocate_matrix(2, 3);
    double **m_2 = allocate_matrix(2, 3);


    m_1[0][0] = -1, m_1[0][1] = 15, m_1[0][2] = 0.14;
    m_1[1][0] = 8.1, m_1[1][1] = 2, m_1[1][2] = 7.17;

    m_2[0][0] = -4, m_2[0][1] = 5, m_2[0][2] = 4.2;
    m_2[1][0] = 12, m_2[1][1] = -2, m_2[1][2] = 55;

    res[0][0] = -5, res[0][1] = 20, res[0][2] = 4.34;
    res[1][0] = 20.1, res[1][1] = 0, res[1][2] = 62.17;

    matrix_addition(m_1, m_2, cur, 2, 3);

    ck_assert_mem_eq(cur[0], res[0], sizeof(double) * 2 * 3);

    free_matrix(res, 1);
    free_matrix(cur, 1);
    free_matrix(m_1, 1);
    free_matrix(m_2, 1);
}
END_TEST


START_TEST(test_mtrx_add_some_and_zero_matrix)
{
    double **res = allocate_matrix(2, 3);
    double **cur = allocate_matrix(2, 3);
    double **m_1 = allocate_matrix(2, 3);
    double **m_2 = allocate_matrix(2, 3);


    m_1[0][0] = -1, m_1[0][1] = 15, m_1[0][2] = 0.14;
    m_1[1][0] = 8.1, m_1[1][1] = 2, m_1[1][2] = 7.17;

    res[0][0] = -1, res[0][1] = 15, res[0][2] = 0.14;
    res[1][0] = 8.1, res[1][1] = 2, res[1][2] = 7.17;

    matrix_addition(m_1, m_2, cur, 2, 3);

    ck_assert_mem_eq(cur[0], res[0], sizeof(double) * 2 * 3);

    free_matrix(res, 1);
    free_matrix(cur, 1);
    free_matrix(m_1, 1);
    free_matrix(m_2, 1);
}
END_TEST


START_TEST(test_mtrx_add_res_zero_matrix)
{
    double **res = allocate_matrix(2, 3);
    double **cur = allocate_matrix(2, 3);
    double **m_1 = allocate_matrix(2, 3);
    double **m_2 = allocate_matrix(2, 3);


    m_1[0][0] = -1, m_1[0][1] = 15, m_1[0][2] = 0.14;
    m_1[1][0] = 8.1, m_1[1][1] = 2, m_1[1][2] = 7.17;

    m_2[0][0] = 1, m_2[0][1] = -15, m_2[0][2] = -0.14;
    m_2[1][0] = -8.1, m_2[1][1] = -2, m_2[1][2] = -7.17;

    matrix_addition(m_1, m_2, cur, 2, 3);

    ck_assert_mem_eq(cur[0], res[0], sizeof(double) * 2 * 3);

    free_matrix(res, 1);
    free_matrix(cur, 1);
    free_matrix(m_1, 1);
    free_matrix(m_2, 1);
}
END_TEST


START_TEST(test_mtrx_add_one_elem_matrix)
{
    double **res = allocate_matrix(1, 1);
    double **cur = allocate_matrix(1, 1);
    double **m_1 = allocate_matrix(1, 1);
    double **m_2 = allocate_matrix(1, 1);


    m_1[0][0] = -1.13;

    m_2[0][0] = -6.72;

    res[0][0] = -7.85;

    matrix_addition(m_1, m_2, cur, 1, 1);

    ck_assert_mem_eq(cur[0], res[0], sizeof(double) * 1 * 1);

    free_matrix(res, 1);
    free_matrix(cur, 1);
    free_matrix(m_1, 1);
    free_matrix(m_2, 1);
}
END_TEST


Suite *mtrx_add_suite(void)
{
    Suite *s = suite_create("mtrx_add_tests");

    TCase *tc_pos;
    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_mtrx_add_some_matrix);
    tcase_add_test(tc_pos, test_mtrx_add_some_and_zero_matrix);
    tcase_add_test(tc_pos, test_mtrx_add_res_zero_matrix);
    tcase_add_test(tc_pos, test_mtrx_add_one_elem_matrix);

    suite_add_tcase(s, tc_pos);

    return s;
}
