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
        for (size_t val : LI) {
            val = gen() % (size * size);
        }
        std::sort(LI.begin(), LI.end());
        int colCounter = -1;
        uint32_t j = 0;
        for (uint32_t i = 0; i < realSize; ++i) {
            if (LI[i] / size > colCounter) {
                LJ[j] = i;
                ++colCounter;
            }
            LI[i] = LI[i] / size;
        }
    } else if (T == CRS){
        LJ.resize(realSize);
        LI.resize(size + 1);
        for (size_t val : LJ) {
            val = gen() % (size * size);
        }
        std::sort(LJ.begin(), LJ.end());
        int rowCounter = -1;
        uint32_t i = 0;
        for (uint32_t j = 0; j < realSize; ++j) {
            if (LJ[j] / size > rowCounter) {
                LI[i] = j;
                ++rowCounter;
            }
            LJ[j] = LJ[j] % size;
        }
    }
}

template<type T, uint16_t coeff>
SparseMatrix<T, coeff>::SparseMatrix(const SparseMatrix<T, coeff>& mat) {
    A = mat.A;
    LI = mat.LI;
    LJ = mat.LJ;
}

template<type T, uint16_t coeff>
void SparseMatrix<T, coeff>::getRandomMatrix(const size_t size) {
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
        for (size_t val : LI) {
            val = gen() % (size * size);
        }
        std::sort(LI.begin(), LI.end());
        int colCounter = -1;
        uint32_t j = 0;
        for (uint32_t i = 0; i < realSize; ++i) {
            if (LI[i] / size > colCounter) {
                LJ[j] = i;
                ++colCounter;
            }
            LI[i] = LI[i] / size;
        }
    }
    else if (T == CRS) {
        LJ.resize(realSize);
        LI.resize(size + 1);
        for (size_t val : LJ) {
            val = gen() % (size * size);
        }
        std::sort(LJ.begin(), LJ.end());
        int rowCounter = -1;
        uint32_t i = 0;
        for (uint32_t j = 0; j < realSize; ++j) {
            if (LJ[j] / size > rowCounter) {
                LI[i] = j;
                ++rowCounter;
            }
            LJ[j] = lJ[j] % size;
        }
    }
}

template<type T, uint16_t coeff>
double SparseMatrix<T, coeff>::getElem(size_t i, size_t j) {
    if (i < 0 || j < 0 || i > A.size() || j > A.size()) {
        throw("Wrong index of element");
    }
    double res = 0.0;
    if (T == CCS) {
        for (size_t k = LJ[j]; k < LJ[j + 1]; ++k) {
            if (LI[k] == i) {
                res = A[k];
                break;
            }
        }
    } else if (T == CRS){
        for (size_t k = LI[i]; k < LI[i + 1]; ++k) {
            if (LJ[k] == j) {
                res = A[k];
                break;
            }
        }
    }
    return res;
}
