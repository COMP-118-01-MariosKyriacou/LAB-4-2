/**
 * \file Matrix.h
 * \brief Function declarations
 * \details Function declarations
 * \author Marios Kyriacou (U244N0037)
 * \date 2025
 * \version 0.1
 * \copyright GNU Public License
 */

#include "namespaces.h"

#ifndef MATRIX_H
#define MATRIX_H

double sumOfRow(const double[][Globals::MAX_COL], const int, const int);
double sumOfCol(const double[][Globals::MAX_COL], const int, const int);
void fillWithRandomNum(double[][Globals::MAX_COL], const int);
void printMatrix(const double [][Globals::MAX_COL], const int);
double maximumValue(const double[][Globals::MAX_COL], const int);
void transposedMatrix(const double[][Globals::MAX_COL], double[][Globals::MAX_COL], const int);
double averageOfElements(const double[][Globals::MAX_COL], const int);

#endif
