/** \file Matrix.h
 *  \brief     A small marix library, header file
 *  \details   The  ..
 *  \author    Harald Gjermundrod
 *  \version   0.1
 *  \date      2020-2020
 *  \pre       First initialize the system.
 *  \bug       No bugs so far
 *  \copyright University of Nicosia.
 */
#pragma once

// Global constant
const int MAX_COL = 5;

bool isIdentityMatrix(const double mat[][MAX_COL], const int maxRow);
bool makeIdentityMatrix(double mat[][MAX_COL], const int maxRow);
double sumOfDiagonal(const double mat[][MAX_COL], const int maxRow);

