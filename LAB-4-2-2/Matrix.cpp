/**
 * \file Matrix.cpp
 * \brief Provides a set of functions
 * \details In this file, we implement various utility functions for working with a fixed-size 2D array (matrix) of double values. These utilities are structured around a matrix defined by a constant number of columns (Globals::MAX_COL) and a variable number of rows (maxRow, passed as a parameter).
 * \author Marios Kyriacou (U244N0037)
 * \date 2025
 * \version 0.1
 * \copyright GNU Public License
 */

#include <iostream>
#include <cstdlib>
#include "Matrix.h"
#include "namespaces.h"

using namespace std;

/**
 * In this function, we sum up all of the items in the row provided by the user
 * @param matrix A constant parameter where it can't be changed with the matrix array
 * @param row A constant variable which holds the value of the row that the user provided
 * @param maxRow A constant variable with the maximum row number in order to check the row
 * @return If the row provided by the user is > maxRow or the row provided is < 0 then it returns 0 otherwise it returns the total of the row
 */
double sumOfRow(const double matrix[][Globals::MAX_COL], const int row, const int maxRow) {
    double total = 0;
    
    if(row > maxRow || row < 0) {
        return 0;
    }
    
    for(int i = 0; i < Globals::MAX_COL; i++) {
        total += matrix[row][i];
    }
    
    return total;
}
