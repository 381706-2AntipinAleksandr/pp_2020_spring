// Copyright 2020 Antipin Alexander
#include <gtest/gtest.h>
#include <vector>
#include "./matrix_multiplication.h"

TEST(Matrix_base, can_multiplicate_dense_matrix) {
    std::vector<double> A = { 1, 2, 3, 4, 5, 7, 1, 5, 8 };
    std::vector<double> B = { 9, 5, 1, 3, 6, 9, 5, 4, 3 };
    std::vector<double> C;
    ASSERT_NO_THROW(matrixMultiplication(A, 3, B, &C));
}

TEST(Matrix_base, can_throw_if_multiplicate_dense_matrix_with_different_size) {
    std::vector<double> A = { 1, 2, 3, 4, 5, 7, 1, 5, 8 };
    std::vector<double> B = { 9, 5, 1, 3, 6, 9, 5, 4};
    std::vector<double> C;
    ASSERT_ANY_THROW(matrixMultiplication(A, 3, B, &C));
}

TEST(Matrix_base, can_multiplicate_dense_matrix_correct_1) {
    std::vector<double> A = { 1, 2, 3, 4, 5, 7, 1, 5, 8 };
    std::vector<double> B = { 9, 5, 1, 3, 6, 9, 5, 4, 3 };
    std::vector<double> C;
    matrixMultiplication(A, 3, B, &C);
    EXPECT_EQ(30, C[0]);
}

TEST(Matrix_base, can_multiplicate_dense_matrix_correct_2) {
    std::vector<double> A = { 1, 2, 3, 4, 5, 7, 1, 5, 8 };
    std::vector<double> B = { 9, 5, 1, 3, 6, 9, 5, 4, 3 };
    std::vector<double> C;
    matrixMultiplication(A, 3, B, &C);
    EXPECT_EQ(78, C[4]);
}

TEST(Matrix_base, can_multiplicate_dense_matrix_correct_3) {
    std::vector<double> A = { 1, 2, 3, 4, 5, 7, 1, 5, 8 };
    std::vector<double> B = { 9, 5, 1, 3, 6, 9, 5, 4, 3 };
    std::vector<double> C;
    matrixMultiplication(A, 3, B, &C);
    EXPECT_EQ(64, C[6]);
}

TEST(Matrix_base, can_create_random_usial_matrix) {
    std::vector<double> A;
    ASSERT_NO_THROW(getRandomMatrix(&A, 100));
}

TEST(Matrix_base, can_create_matrix) {
    ASSERT_NO_THROW((SparseMatrix<CCS>(1000, 10)));
}

TEST(Matrix_base, can_throw_if_it_is_not_a_sparse_matrix) {
    ASSERT_ANY_THROW((SparseMatrix<CCS>(100, 5)));
}

TEST(Matrix_base, can_return_element) {
    SparseMatrix<CCS> A(100);
    ASSERT_NO_THROW(A.getElem(50, 25));
}

TEST(Matrix_base, can_construct_not_random_matrix_without_throws) {
    std::vector<double> A = { 8.0, 5.0, 2.0, 4.0, 9.0, 1.0, 3.0 };
    std::vector<size_t> LI = { 5, 2, 0, 5, 3, 3, 4 };
    std::vector<size_t> LJ = { 0, 1, 2, 3, 4, 5, 7 };
    SparseMatrix<CCS> mat(6);
    ASSERT_NO_THROW(mat.setMatrix(A, LI, LJ, 6));
}

TEST(Matrix_base, can_return_not_random_matrix_correct_1) {
    std::vector<double> A = { 8.0, 5.0, 2.0, 4.0, 9.0, 1.0, 3.0 };
    std::vector<size_t> LI = { 5, 2, 0, 5, 3, 3, 4 };
    std::vector<size_t> LJ = { 0, 1, 2, 3, 4, 5, 7 };
    SparseMatrix<CCS> mat(6);
    mat.setMatrix(A, LI, LJ, 6);
    EXPECT_EQ(9, mat.getElem(3, 4));
}

TEST(Matrix_base, can_return_not_random_matrix_correct_2) {
    std::vector<double> A = { 8.0, 5.0, 2.0, 4.0, 9.0, 1.0, 3.0 };
    std::vector<size_t> LI = { 5, 2, 0, 5, 3, 3, 4 };
    std::vector<size_t> LJ = { 0, 1, 2, 3, 4, 5, 7 };
    SparseMatrix<CCS> mat(6);
    mat.setMatrix(A, LI, LJ, 6);
    EXPECT_EQ(5, mat.getElem(2, 1));
}

TEST(Matrix_base, can_convert_matrix_from_CCR_to_CRS) {
    std::vector<double> A = { 8.0, 5.0, 2.0, 4.0, 9.0, 1.0, 3.0 };
    std::vector<size_t> LI = { 5, 2, 0, 5, 3, 3, 4 };
    std::vector<size_t> LJ = { 0, 1, 2, 3, 4, 5, 7 };
    SparseMatrix<CCS> mat(6);
    mat.setMatrix(A, LI, LJ, 6);
    SparseMatrix<CRS> mat2(6);
    ASSERT_NO_THROW(convertMatrix(mat, &mat2));
}

TEST(Marix_base, can_convert_matrix_from_CCR_to_CRS_correct_1) {
    std::vector<double> A = { 2.0, 5.0, 8.0, 1.0, 4.0, 9.0, 1.0, 1.0, 3.0 };
    std::vector<size_t> LI = { 0, 2, 5, 0, 5, 3, 2, 3, 5 };
    std::vector<size_t> LJ = { 0, 0, 3, 3, 5, 6, 9 };
    SparseMatrix<CCS> mat(6);
    mat.setMatrix(A, LI, LJ, 6);
    SparseMatrix<CRS> mat2(6);
    convertMatrix(mat, &mat2);
    EXPECT_EQ(mat.getElem(2, 1), 5);
}

TEST(Marix_base, can_convert_matrix_from_CCR_to_CRS_correct_2) {
    std::vector<double> A = { 2.0, 5.0, 8.0, 1.0, 4.0, 9.0, 1.0, 1.0, 3.0 };
    std::vector<size_t> LI = { 0, 2, 5, 0, 5, 3, 2, 3, 5 };
    std::vector<size_t> LJ = { 0, 0, 3, 3, 5, 6, 9 };
    SparseMatrix<CCS> mat(6);
    mat.setMatrix(A, LI, LJ, 6);
    SparseMatrix<CRS> mat2(6);
    convertMatrix(mat, &mat2);
    EXPECT_EQ(mat.getElem(5, 3), 4);
}

TEST(Matrix_base, can_convert_matrix_from_CRS_to_CCR) {
    std::vector<double> A = { 2.0, 5.0, 9.0, 1.0, 3.0, 8.0, 4.0 };
    std::vector<size_t> LI = { 0, 1, 1, 2, 4, 5, 7 };
    std::vector<size_t> LJ = { 2, 1, 4, 5, 5, 0, 3 };
    SparseMatrix<CRS> mat(6);
    mat.setMatrix(A, LI, LJ, 6);
    SparseMatrix<CCS> mat2(6);
    ASSERT_NO_THROW(convertMatrix(mat, &mat2));
}

TEST(Marix_base, can_convert_matrix_from_CRS_to_CCR_correct_1) {
    std::vector<double> A = { 2.0, 1.0, 5.0, 1.0, 9.0, 1.0, 8.0, 4.0, 3.0 };
    std::vector<size_t> LI = { 0, 2, 2, 4, 6, 6, 9 };
    std::vector<size_t> LJ = { 1, 3, 1, 5, 4, 5, 1, 3, 5 };
    SparseMatrix<CRS> mat(6);
    mat.setMatrix(A, LI, LJ, 6);
    SparseMatrix<CCS> mat2(6);
    convertMatrix(mat, &mat2);
    EXPECT_EQ(mat.getElem(2, 1), 5);
}

TEST(Marix_base, can_convert_matrix_from_CRS_to_CCR_correct_2) {
    std::vector<double> A = { 2.0, 1.0, 5.0, 1.0, 9.0, 1.0, 8.0, 4.0, 3.0 };
    std::vector<size_t> LI = { 0, 2, 2, 4, 6, 6, 9 };
    std::vector<size_t> LJ = { 1, 3, 1, 5, 4, 5, 1, 3, 5 };
    SparseMatrix<CRS> mat(6);
    mat.setMatrix(A, LI, LJ, 6);
    SparseMatrix<CCS> mat2(6);
    convertMatrix(mat, &mat2);
    EXPECT_EQ(mat.getElem(3, 4), 9);
}

TEST(Matrix_multiplication, can_multiply_matrices) {
    std::vector<double> A = { 8.0, 5.0, 2.0, 4.0, 9.0, 1.0, 3.0 };
    std::vector<size_t> LI = { 5, 2, 0, 5, 3, 3, 4 };
    std::vector<size_t> LJ = { 0, 1, 2, 3, 4, 5, 7 };
    SparseMatrix<CCS> mat(6);
    mat.setMatrix(A, LI, LJ, 6);

    std::vector<double> A1 = { 2.0, 5.0, 8.0, 1.0, 4.0, 9.0, 1.0, 1.0, 3.0 };
    std::vector<size_t> LI1 = { 0, 2, 5, 0, 5, 3, 2, 3, 5 };
    std::vector<size_t> LJ1 = { 0, 0, 3, 3, 5, 6, 9 };
    SparseMatrix<CCS> mat1(6);
    mat1.setMatrix(A1, LI1, LJ1, 6);

    SparseMatrix<CCS> res;

    ASSERT_NO_THROW(getSequentialMatrixMultiplication(mat, mat1, &res));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
