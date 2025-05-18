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

/**
  * Create a square with the desired size. The boolean filled is so it checks if it wants it filled or not. The boolean will be <code>false</code> if it wasn't called by the user, hence the shape will not be filled. If the function gets called from the random shape generator then it gets the default state of not-filled.
  * @param size The size variable is both the width and height of the square
  * @param ch The ch variable is the desired character that they want the shape to have
  * @param filled Checks if the function has been called from the random number generator or from the user
 */
void drawSquare(const int size, const char ch, const bool filled){
    assert(size > 0);
    
    char tempAns;
    
    if(!filled) {
        // Prompt user to ask them if they want the square filled or empty
        cout << "Would you like a filled square (y/n)? ";
        cin >> tempAns;
        
        // Data validation for yes and no
        while(tempAns != 'y' && tempAns != 'n') {
            cout << tempAns;
            cout << "Please enter y or n: ";
            cin >> tempAns;
        }
    }
    
    // If the answer is y then draw a filled square otherwise draw an empty square
    if(tempAns == 'y') drawSquareFilled(size, ch);
    else {
        // Loop through the size. If it's the first row, draw the whole row. Any other row, draw a character add a space of
        // size - 1 (setw starts from 1, so we remove 1 from size) and add another character
        for(int i = 0; i < size; i++) {
            if(i == 0 || i == size - 1) {
                for(int j = 0; j < size; j++) {
                    cout << ch;
                }
                cout << endl;
            } else {
                cout << ch << setw(size - 1) << ch;
                cout << endl;
            }
        }
        
        cout << endl;
    }
}

/**
  * Draw a filled square on the users screen
  * @param size The size variable is both the width and height of the square
  * @param ch The ch variable is the desired character that they want the shape to have
 */
void drawSquareFilled(const int size, const char ch){
    assert(size > 0);
    
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << ch;
        }
        cout << endl;
    }
    
    cout << endl;
}
