// Copyright 2020 Antipin Alexander
#ifndef MODULES_TASK_1_TEST_ANTIPIN_A_MATRIX_MULTIPLICATION_MATRIX_MULTIPLICATION_H_
#define MODULES_TASK_1_TEST_ANTIPIN_A_MATRIX_MULTIPLICATION_MATRIX_MULTIPLICATION_H_

#include <vector>

enum type
{
    CRS,
    CCS
};

template <type T, uint16_t coeff>
class SparseMatrix
{
public:
    SparseMatrix(const size_t size = 1);
    SparseMatrix(const SparseMatrix<T, coeff>& mat);
    void getRandomMatrix();
    double getElem(size_t i, size_t j);
private:
    std::vector<double> A;
    std::vector<size_t> LI;
    std::vector<size_t> LJ;
};

int getSequentialOperations(std::vector<int> vec);

#endif  // MODULES_TASK_1_TEST_ANTIPIN_A_MATRIX_MULTIPLICATION_MATRIX_MULTIPLICATION_H_
