// Copyright 2020 Antipin Alexander
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include "../../../modules/task_1/antipin_a_matrix_multiplication/matrix_multiplication.h"

template <type T, uint16_t coeff>
SparseMatrix<T, coeff>::SparseMatrix(const size_t size) {
    if (coeff <= 5) {
        throw("So small coefficient, it is not a sparse matrix");
    }
    size_t realSize = (size * size) / coeff;
    A.resize(realSize);
    std::mt19937 gen;
    gen.seed(static_cast<unsigned int>(time(0)));
    for (double val : A) {
        val = gen() % 100;
    }
    if (T == CCS) {
        LI.resize(realSize);
        LJ.resize(size + 1);
    } else if (T == CRS){
        LJ.resize(realSize);
        LI.resize(size + 1);
    }
}

std::vector<int> getRandomVector(int sz) {
    std::mt19937 gen;
    gen.seed(static_cast<unsigned int>(time(0)));
    std::vector<int> vec(sz);
    for (int  i = 0; i < sz; i++) { vec[i] = gen() % 100; }
    return vec;
}
