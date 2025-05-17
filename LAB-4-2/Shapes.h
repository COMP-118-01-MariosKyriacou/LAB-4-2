/**
 * \file Shapes.h
 * \brief Library to draw various shapes
 * \details This is a illustration of a multi-file project in order to learn how to use .h files (header files)
 * \author Marios Kyriacou (U244N0037)
 * \version 0.1
 * \date 2025
 * \pre First initialize the system
 * \copyright GNU Public License
 */

#ifndef SHAPES_H
#define SHAPES_H

void drawHorizontalLine(const int, const char);
void drawVerticalLine(const int, const char);
void drawSquare(const int, const char, const bool);
void drawSquareFilled(const int, const char);
void drawRectangle(const int, const int, const char, const bool);
void drawRectangleFilled(const int, const int, const char);
void drawPyramid(const int, const char);
void drawTriangle(const int, const char);
bool dataValidation(const int, const int);
void drawShapes(const int);
void initializeArrays(int[], int[], char[], const int);
void drawArrays(const int[], const int[], const char[], const int);

#endif
