// Copyright 2020 Antipin Alexander
#include <gtest/gtest.h>
#include <vector>
#include "./matrix_multiplication.h"

TEST(Matrix_base, can_create_matrix) {
    SparseMatrix<CCS, 6> some(100);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
