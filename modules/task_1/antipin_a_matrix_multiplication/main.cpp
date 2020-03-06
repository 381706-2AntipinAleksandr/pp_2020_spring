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
    ASSERT_NO_THROW(mat.setMatrix(A, LI, LJ));
}

TEST(Matrix_base, can_return_not_random_matrix_correct_1) {
    std::vector<double> A = { 8.0, 5.0, 2.0, 4.0, 9.0, 1.0, 3.0 };
    std::vector<size_t> LI = { 5, 2, 0, 5, 3, 3, 4 };
    std::vector<size_t> LJ = { 0, 1, 2, 3, 4, 5, 7 };
    SparseMatrix<CCS> mat(6);
    mat.setMatrix(A, LI, LJ);
    EXPECT_EQ(9, mat.getElem(3, 4));
}

TEST(Matrix_base, can_return_not_random_matrix_correct_2) {
    std::vector<double> A = { 8.0, 5.0, 2.0, 4.0, 9.0, 1.0, 3.0 };
    std::vector<size_t> LI = { 5, 2, 0, 5, 3, 3, 4 };
    std::vector<size_t> LJ = { 0, 1, 2, 3, 4, 5, 7 };
    SparseMatrix<CCS> mat(6);
    mat.setMatrix(A, LI, LJ);
    EXPECT_EQ(5, mat.getElem(2, 1));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
