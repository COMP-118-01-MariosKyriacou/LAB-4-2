/**
 * \file Shapes.cpp
 * \brief Functions for all shapes
 * \details In this file, we have all the functions that are used coded and tested
 * \author Marios Kyriacou (U244N0037)
 * \date 2025
 * \version 0.1
 * \copyright GNU Public License
 */

#include <iostream>
#include <iomanip>
#include <cassert>
#include "Shapes.h"

using namespace std;

/**
  * Loop from 0 to the desired length and output the character in one straight line. Once it ends add a new line
  * @param length The length variable is the desired length of the line that the user wants to output
  * @param ch The ch variable is the desired character that they want the shape to have
 */
void drawHorizontalLine(const int length, const char ch) {
    assert(length > 0);
    
    for(int i = 0; i < length; i++) {
        cout << ch;
    }
    
    cout << endl;
}

/**
  * Loop from 0 to the desired height and output a character in each line. Once it ends add a new line
  * @param height The height variable is the desired length of the line that the user wants to output
  * @param ch The ch variable is the desired character that they want the shape to have
 */
void drawVerticalLine(const int height, const char ch) {
    assert(height > 0);
    
    for(int i = 0; i < height; i++) {
        cout << ch << endl;
    }
    
    cout << endl;
}
