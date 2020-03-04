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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
