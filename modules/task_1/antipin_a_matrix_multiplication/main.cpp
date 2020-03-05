// Copyright 2020 Antipin Alexander
#include <gtest/gtest.h>
#include <vector>
#include "./matrix_multiplication.h"

TEST(Matrix_base, can_create_matrix) {
    ASSERT_NO_THROW((SparseMatrix<CCS, 10>(1000)));
}

TEST(Matrix_base, can_throw_if_it_is_not_a_sparse_matrix) {
    ASSERT_ANY_THROW((SparseMatrix<CCS, 4>(100)));
}

TEST(Matrix_base, can_return_element) {
    SparseMatrix<CCS, 10> A(100);
    ASSERT_NO_THROW(A.getElem(50, 25));
}

TEST(Matrix_base, can_construct_not_random_matrix_without_throws) {
    std::vector<double> A = { 8.0, 5.0, 2.0, 4.0, 9.0, 1.0, 3.0 };
    std::vector<size_t> LI = { 5, 2, 0, 5, 3, 3, 4 };
    std::vector<size_t> LJ = { 0, 1, 2, 3, 4, 5, 7 };
    SparseMatrix<CCS, 6> mat(6);
    ASSERT_NO_THROW(mat.setMatrix(A, LI, LJ));
}

TEST(Matrix_base, can_return_not_random_matrix_correct_1) {
    std::vector<double> A = { 8.0, 5.0, 2.0, 4.0, 9.0, 1.0, 3.0 };
    std::vector<size_t> LI = { 5, 2, 0, 5, 3, 3, 4 };
    std::vector<size_t> LJ = { 0, 1, 2, 3, 4, 5, 7 };
    SparseMatrix<CCS, 6> mat(6);
    mat.setMatrix(A, LI, LJ);
    EXPECT_EQ(9, mat.getElem(3, 4));
}

TEST(Matrix_base, can_return_not_random_matrix_correct_2) {
    std::vector<double> A = { 8.0, 5.0, 2.0, 4.0, 9.0, 1.0, 3.0 };
    std::vector<size_t> LI = { 5, 2, 0, 5, 3, 3, 4 };
    std::vector<size_t> LJ = { 0, 1, 2, 3, 4, 5, 7 };
    SparseMatrix<CCS, 6> mat(6);
    mat.setMatrix(A, LI, LJ);
    EXPECT_EQ(5, mat.getElem(2, 1));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
