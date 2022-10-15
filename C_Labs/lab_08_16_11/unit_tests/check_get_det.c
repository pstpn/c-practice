#include <stdlib.h>
#include <check.h>

#include "../inc/my_def.h"
#include "../inc/my_err.h"
#include "../inc/tools.h"
#include "../inc/w_w_mtrx.h"


double get_det(double **mtrx, int n)
{
    double det = 1;


    for (int k = 0; k < n; ++k)
    {
        if (mtrx[k][k] >= 0 && mtrx[k][k] <= 0)
        {
            int ind = get_nonzero(mtrx, k, k + 1, n);


            if (ind < 0 || (k && get_nonzero(mtrx, k - 1, k, n) < 0))
            {
                det = 0;
                break;
            }
            
            addition_or_sub_strs(mtrx[k], mtrx[ind], n, FALSE);
        }

        for (int i = k + 1; i < n; ++i)
            if (!(mtrx[i][k] >= 0 && mtrx[i][k] <= 0))
            {
                div_str(mtrx[k] + k + 1, n - (k + 1), (double) mtrx[k][k] / mtrx[i][k]);
                addition_or_sub_strs(mtrx[i] + k + 1, mtrx[k] + k + 1, n - (k + 1), TRUE);
                div_str(mtrx[k] + k + 1, n - (k + 1), (double) mtrx[i][k] / mtrx[k][k]);
                mtrx[i][k] = 0;
            }

        det *= mtrx[k][k];
    }

    return (double) det;
}


START_TEST(test_get_det_zero_matrix)
{
    double **ptrs = allocate_matrix(3, 3);

    double pos_det = 0.0;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            ptrs[i][j] = 0.0;

    double det = get_det(ptrs, 3);

    ck_assert_double_eq(det, pos_det);

    free_matrix(ptrs, 1);
}
END_TEST


START_TEST(test_get_det_some_matrix)
{
    double **ptrs = allocate_matrix(2, 2);
    ptrs[0][0] = 14.03;
    ptrs[0][1] = -33.3;
    ptrs[1][0] = 4.101;
    ptrs[1][1] = 1.1;

    double pos_det = 151.9963;
    

    double det = get_det(ptrs, 2);

    ck_assert_double_eq(det, pos_det);

    free_matrix(ptrs, 1);
}
END_TEST


START_TEST(test_get_det_one_elem_matrix)
{
    double **ptrs = allocate_matrix(1, 1);
    ptrs[0][0] = -8.923;

    double pos_det = -8.923;
    

    double det = get_det(ptrs, 1);

    ck_assert_double_eq(det, pos_det);

    free_matrix(ptrs, 1);
}
END_TEST


START_TEST(test_get_det_zero_col_matrix)
{
    double **ptrs = allocate_matrix(2, 2);
    ptrs[0][0] = 0;
    ptrs[0][1] = -33.3;
    ptrs[1][0] = 0;
    ptrs[1][1] = 1.1;

    double pos_det = 0;
    

    double det = get_det(ptrs, 2);

    ck_assert_double_eq(det, pos_det);

    free_matrix(ptrs, 1);
}
END_TEST


START_TEST(test_get_det_zero_row_matrix)
{
    double **ptrs = allocate_matrix(2, 2);
    ptrs[0][0] = 0;
    ptrs[0][1] = 0;
    ptrs[1][0] = 4.101;
    ptrs[1][1] = 1.1;

    double pos_det = 0;
    

    double det = get_det(ptrs, 2);

    ck_assert_double_eq(det, pos_det);

    free_matrix(ptrs, 1);
}
END_TEST


Suite *get_det_suite(void)
{
    Suite *s = suite_create("get_det_tests");

    TCase *tc_pos;
    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_get_det_zero_matrix);
    tcase_add_test(tc_pos, test_get_det_some_matrix);
    tcase_add_test(tc_pos, test_get_det_one_elem_matrix);
    tcase_add_test(tc_pos, test_get_det_zero_col_matrix);
    tcase_add_test(tc_pos, test_get_det_zero_row_matrix);

    suite_add_tcase(s, tc_pos);

    return s;
}
