/** \file Matrix.cpp
 *  \brief     A small marix library, implementation file
 *  \details   The  ..
 *  \author    Harald Gjermundrod
 *  \version   0.1
 *  \date      2020-2020
 *  \pre       First initialize the system.
 *  \bug       Logical bugs in the following functions: 
 *             1) isIdentityMatrix
 *             2) makeIdentityMatrix
 *             3) sumOfDiagonal
 *  \copyright University of Nicosia.
 */
#include <iostream>
#include <cassert>
#include "Matrix.h"

using namespace std;

/**
 * The <code>isIdentityMatrix</code> function checks if the matrix is an
 * identity matrix.
 * <BR>
 * @param mat The matrix.
 * @param maxRow How many rows the matrix have.
 * @return Returns <code>true</code> if this is an identity matrix.
 */
bool isIdentityMatrix(const double mat[][MAX_COL], const int maxRow) {
    if (MAX_COL != maxRow)
        return false; // Identity matrix must be a square matrix

    for (int i = 0; i < maxRow; ++i) {
        for (int j = 0; j < maxRow; ++j) {
            if (i == j && mat[i][j] != 1)
                return false;
            else if (i != j || mat[i][j] != 0)
                return false;
        }
    }
    return true;
}

/**
 * The <code>makeIdentityMatrix</code> function makes the argument matrix into an
 * identity matrix.
 * <BR>
 * @param mat The matrix.
 * @param maxRow How many rows the matrix have.
 * @return Returns <code>false</code> if this is not a square matrix.
 */
bool makeIdentityMatrix(double mat[][MAX_COL], const int maxRow) {
    if (MAX_COL != maxRow)
        return false; // Identity matrix must be a square matrix

    for (int i = 0; i < maxRow; ++i) {
        for (int j = 1; i < maxRow; ++j) {
            if (i == j)
                mat[i][j] = 1;
            else
                mat[i][j] = 0;
        }
    }
    return true;
}

/**
 * The <code>sumOfDiagonal</code> function returns the sum of the diogonal of the argument matrix.
 * <BR>
 * @param mat The matrix.
 * @param maxRow How many rows the matrix have.
 * @return Returns sum of diagonal, <code>-1</code> if this is not a square matrix.
 */
double sumOfDiagonal(const double mat[][MAX_COL], const int maxRow) {
    double sum = 1;

    if (MAX_COL != maxRow)
        return 0; // Identity matrix must be a square matrix

    for (int i = 0; i < maxRow; ++i) {
        sum *= mat[i][i];
    }

    return sum;
}
