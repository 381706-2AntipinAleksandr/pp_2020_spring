// Copyright 2020 Antipin Alexander
#ifndef MODULES_TASK_1_ANTIPIN_A_MATRIX_MULTIPLICATION_MATRIX_MULTIPLICATION_H_
#define MODULES_TASK_1_ANTIPIN_A_MATRIX_MULTIPLICATION_MATRIX_MULTIPLICATION_H_

#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

enum type {
    CRS,
    CCS
};

template <type T = CCS>
class SparseMatrix {
 public:
    explicit SparseMatrix(const size_t size = 1, const uint16_t coeff = 6);
    SparseMatrix(const SparseMatrix<T>& mat);
    void getRandomMatrix(const size_t size, const uint16_t coeff);
    double getElem(const size_t i, const size_t j);
    void setElem(const double elem, const size_t i, const size_t j);
    void setMatrix(const std::vector<double>& A, const std::vector<size_t>& LI, const std::vector<size_t>& LJ);
 private:
    std::vector<double> A;
    std::vector<size_t> LI;
    std::vector<size_t> LJ;
};

template <type T>
SparseMatrix<T>::SparseMatrix(const size_t size, const uint16_t coeff) {
    if (coeff <= 5) {
        throw("So small coefficient, it is not a sparse matrix");
    }
    size_t realSize = (size * size) / coeff;
    A.resize(realSize);
    std::mt19937 gen;
    gen.seed(static_cast<unsigned int>(time(0)));
    for (double& val : A) {
        val = gen() % 100;
    }
    if (T == CCS) {
        LI.resize(realSize);
        LJ.resize(size + 1);
        for (size_t& val : LI) {
            val = gen() % (size * size);
        }
        std::sort(LI.begin(), LI.end());
        int colCounter = 0;
        uint32_t j = 0;
        for (uint32_t i = 0; i < realSize; ++i) {
            if (LI[i] / size >= colCounter) {
                LJ[j] = i;
                ++j;
                ++colCounter;
            }
            LI[i] = LI[i] % size;
        }
        LJ[j] = realSize;
    } else if (T == CRS) {
        LJ.resize(realSize);
        LI.resize(size + 1);
        for (size_t& val : LJ) {
            val = gen() % (size * size);
        }
        std::sort(LJ.begin(), LJ.end());
        int rowCounter = 0;
        uint32_t i = 0;
        for (uint32_t j = 0; j < realSize; ++j) {
            if (LJ[j] / size >= rowCounter) {
                LI[i] = j;
                ++i;
                ++rowCounter;
            }
            LJ[j] = LJ[j] % size;
        }
        LI[i] = realSize;
    }
}

template<type T>
SparseMatrix<T>::SparseMatrix(const SparseMatrix<T>& mat) {
    A = mat.A;
    LI = mat.LI;
    LJ = mat.LJ;
}

template<type T>
void SparseMatrix<T>::getRandomMatrix(const size_t size, const uint16_t coeff) {
    size_t realSize = (size * size) / coeff;
    A.resize(realSize);
    std::mt19937 gen;
    gen.seed(static_cast<unsigned int>(time(0)));
    for (double& val : A) {
        val = gen() % 100;
    }
    if (T == CCS) {
        LI.resize(realSize);
        LJ.resize(size + 1);
        for (size_t& val : LI) {
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
    } else if (T == CRS) {
        LJ.resize(realSize);
        LI.resize(size + 1);
        for (size_t& val : LJ) {
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

template<type T>
double SparseMatrix<T>::getElem(const size_t i, const size_t j) {
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
    } else if (T == CRS) {
        for (size_t k = LI[i]; k < LI[i + 1]; ++k) {
            if (LJ[k] == j) {
                res = A[k];
                break;
            }
        }
    }
    return res;
}

template<type T>
void SparseMatrix<T>::setElem(const double elem, const size_t i, const size_t j) {
    if (A.size() < i || A.size() < j || i < 0 || j < 0) {
        throw("Out of matrix range");
    }
}

template<type T>
void SparseMatrix<T>::setMatrix(const std::vector<double>& A, const std::vector<size_t>&
    LI, const std::vector<size_t>& LJ) {
    if (T == CCS) {
        if (LJ.size() > LI.size()) {
            throw("Wrong matrix type");
        }
    } else {
        if (LI.size() > LJ.size()) {
            throw("Wrong matrix type");
        }
    }
    this->A = A;
    this->LI = LI;
    this->LJ = LJ;
}

void matrixMultiplication(const std::vector<double>& A, const size_t n, const std::vector<double>& B,
    std::vector<double>* C);

double isZero(const double nomber);

void getSequentialMatrixMultiplication(const SparseMatrix<CCS>& A, const SparseMatrix<CCS>& B, SparseMatrix<CCS>* C);

#endif  // MODULES_TASK_1_ANTIPIN_A_MATRIX_MULTIPLICATION_MATRIX_MULTIPLICATION_H_
