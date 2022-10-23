#include <stdio.h>
#include <check.h>

#include "../inc/w_w_mem.h"


void matrix_product(double **mtrx_1, double **mtrx_2, double **cur, int n_2_m_1, int n_1, int m_2)
{
    double buf;


    for (int i = 0; i < n_1; ++i)
    {
        for (int j = 0; j < m_2; ++j)
        {
            buf = 0;

            for (int k = 0; k < n_2_m_1; ++k)
                buf += mtrx_1[i][k] * mtrx_2[k][j];
            
            cur[i][j] = buf;
        }
    }
}


START_TEST(test_mtrx_prod_some_matrix)
{
    double **res = allocate_matrix(3, 4);
    double **cur = allocate_matrix(3, 4);
    double **m_1 = allocate_matrix(3, 2);
    double **m_2 = allocate_matrix(2, 4);


    m_1[0][0] = 4, m_1[0][1] = -2;
    m_1[1][0] = 5, m_1[1][1] = 5;
    m_1[2][0] = 17, m_1[2][1] = 3;

    m_2[0][0] = 5, m_2[0][1] = 67, m_2[0][2] = 0, m_2[0][3] = 22;
    m_2[1][0] = 15, m_2[1][1] = 15, m_2[1][2] = 6, m_2[1][3] = -12;

    res[0][0] = -10, res[0][1] = 238, res[0][2] = -12, res[0][3] = 112;
    res[1][0] = 100, res[1][1] = 410, res[1][2] = 30, res[1][3] = 50;
    res[2][0] = 130, res[2][1] = 1184, res[2][2] = 18, res[2][3] = 338;

    matrix_product(m_1, m_2, cur, 2, 3, 4);

    ck_assert_mem_eq(cur[0], res[0], sizeof(double) * 3 * 4);

    free_matrix(res, 1);
    free_matrix(cur, 1);
    free_matrix(m_1, 1);
    free_matrix(m_2, 1);
}
END_TEST


START_TEST(test_mtrx_prod_some_and_identify_matrix)
{
    double **res = allocate_matrix(2, 3);
    double **cur = allocate_matrix(2, 3);
    double **m_1 = allocate_matrix(2, 3);
    double **m_2 = allocate_matrix(3, 3);


    m_1[0][0] = -4.15, m_1[0][1] = 2.2, m_1[0][2] = 0.6;
    m_1[1][0] = 77.1, m_1[1][1] = 2, m_1[1][2] = 1;

    m_2[0][0] = 1, m_2[0][1] = 1, m_2[0][2] = 1;
    m_2[1][0] = 1, m_2[1][1] = 1, m_2[1][2] = 1;
    m_2[2][0] = 1, m_2[2][1] = 1, m_2[2][2] = 1;

    res[0][0] = -1.35, res[0][1] = -1.35, res[0][2] = -1.35;
    res[1][0] = 80.1, res[1][1] = 80.1, res[1][2] = 80.1;

    matrix_product(m_1, m_2, cur, 3, 2, 3);

    ck_assert_mem_eq(cur[0], res[0], sizeof(double) * 2 * 3);

    free_matrix(res, 1);
    free_matrix(cur, 1);
    free_matrix(m_1, 1);
    free_matrix(m_2, 1);
}
END_TEST


START_TEST(test_mtrx_prod_res_zero_matrix)
{
    double **res = allocate_matrix(2, 2);
    double **cur = allocate_matrix(2, 2);
    double **m_1 = allocate_matrix(2, 2);
    double **m_2 = allocate_matrix(2, 2);


    m_2[0][0] = 14, m_2[0][1] = 16;
    m_2[1][0] = 3.33, m_2[1][1] = -7.0023;

    matrix_product(m_1, m_2, cur, 2, 2, 2);

    ck_assert_mem_eq(cur[0], res[0], sizeof(double) * 2 * 2);

    free_matrix(res, 1);
    free_matrix(cur, 1);
    free_matrix(m_1, 1);
    free_matrix(m_2, 1);
}
END_TEST


START_TEST(test_mtrx_prod_one_row_and_one_col_matrix)
{
    double **res = allocate_matrix(1, 1);
    double **cur = allocate_matrix(1, 1);
    double **m_1 = allocate_matrix(1, 3);
    double **m_2 = allocate_matrix(3, 1);


    m_1[0][0] = -88.4, m_1[0][1] = 14, m_1[0][2] = 0.01;

    m_2[0][0] = 2.21;
    m_2[1][0] = 0;
    m_2[2][0] = 17.71;

    res[0][0] = -195.1869;

    matrix_product(m_1, m_2, cur, 3, 1, 1);

    ck_assert_mem_eq(cur[0], res[0], sizeof(double) * 1 * 1);

    free_matrix(res, 1);
    free_matrix(cur, 1);
    free_matrix(m_1, 1);
    free_matrix(m_2, 1);
}
END_TEST


START_TEST(test_mtrx_prod_one_elem_matrix)
{
    double **res = allocate_matrix(1, 1);
    double **cur = allocate_matrix(1, 1);
    double **m_1 = allocate_matrix(1, 1);
    double **m_2 = allocate_matrix(1, 1);


    m_1[0][0] = 2;

    m_2[0][0] = 13;

    res[0][0] = 26;

    matrix_product(m_1, m_2, cur, 1, 1, 1);

    ck_assert_mem_eq(cur[0], res[0], sizeof(double) * 1 * 1);

    free_matrix(res, 1);
    free_matrix(cur, 1);
    free_matrix(m_1, 1);
    free_matrix(m_2, 1);
}
END_TEST


START_TEST(test_mtrx_prod_unzero_mtrxs_res_zero_matrix)
{
    double **res = allocate_matrix(2, 2);
    double **cur = allocate_matrix(2, 2);
    double **m_1 = allocate_matrix(2, 2);
    double **m_2 = allocate_matrix(3, 2);


    m_1[0][0] = 1, m_1[0][1] = -1;
    m_1[1][0] = 1, m_1[1][1] = -1;

    m_2[0][0] = 1, m_2[0][1] = 1;
    m_2[1][0] = 1, m_2[1][1] = 1;

    matrix_product(m_1, m_2, cur, 2, 2, 2);

    ck_assert_mem_eq(cur[0], res[0], sizeof(double) * 2 * 2);

    free_matrix(res, 1);
    free_matrix(cur, 1);
    free_matrix(m_1, 1);
    free_matrix(m_2, 1);
}
END_TEST


Suite *mtrx_prod_suite(void)
{
    Suite *s = suite_create("mtrx_prod_tests");

    TCase *tc_pos;
    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_mtrx_prod_some_matrix);
    tcase_add_test(tc_pos, test_mtrx_prod_some_and_identify_matrix);
    tcase_add_test(tc_pos, test_mtrx_prod_res_zero_matrix);
    tcase_add_test(tc_pos, test_mtrx_prod_one_row_and_one_col_matrix);
    tcase_add_test(tc_pos, test_mtrx_prod_one_elem_matrix);
    tcase_add_test(tc_pos, test_mtrx_prod_unzero_mtrxs_res_zero_matrix);

    suite_add_tcase(s, tc_pos);

    return s;
}
