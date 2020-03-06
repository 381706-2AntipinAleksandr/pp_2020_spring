// Copyright 2020 Antipin Alexander
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include "../../../modules/task_1/antipin_a_matrix_multiplication/matrix_multiplication.h"

void matrixMultiplication(const std::vector<double>& A, const size_t n, const std::vector<double>& B,
    std::vector<double>* C) {
    if (A.size() != B.size()) {
        throw("Wrong matrix size");
    }
    (*C).resize(A.size());
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            for (size_t k = 0; k < n; ++k) {
                (*C)[i * n + j] += isZero(A[i * n + k] * B[k * n + j]);
            }
        }
    }
}

double isZero(const double number) {
    if (std::abs(number) < 0.0000000001) {
        return 0.0;
    } else {
        return number;
    }
}

void getSequentialMatrixMultiplication(const SparseMatrix<CCS>& A, const SparseMatrix<CCS>& B, SparseMatrix<CCS>* C) {
}
