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

/**
  * Display the desired rectangle dimensions (i = height, j = length). At the end add a new line. The boolean will be <code>false</code> if it wasn't called by the user, hence the shape will not be filled. If the function gets called from the random shape generator then it gets the default state of not-filled.
  * @param height The height variable is the height of the rectangle
  * @param length The length variable is the length of the rectangle
  * @param ch The ch variable is the desired character that they want the shape to have
  * @param filled The filled variable is in order for us to know if the function was called by a user or not
 */
void drawRectangle(const int height, const int length, const char ch, const bool filled){
    assert(height > 0 && length > 0);
    
    // Temporary Variables
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
    
    // Loop through the size. If it's the first row, draw the whole row. Any other row, draw a character add a space of
    // length - 1 (setw starts from 1, so we remove 1 from size) and add another character
    if(tempAns == 'y') drawRectangleFilled(height, length, ch);
    else {
        for(int i = 0; i < height; i++) {
            if(i == 0 || i == height - 1) {
                for(int j = 0; j < length; j++) {
                    cout << ch;
                }
            } else {
                cout << ch << setw(length - 1) << ch;
            }
            
            cout << endl;
        }
    }
    
    cout << endl;
}

/**
  * Draw a filled rectangle with the desired height and length
  * @param height The height variable is the height of the rectangle
  * @param length The length variable is the length of the rectangle
  * @param ch The ch variable is the desired character that they want the shape to have
 */
void drawRectangleFilled(const int height, const int length, const char ch){
    assert(height > 0 && length > 0);
    
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < length; j++) {
            cout << ch;
        }
        
        cout << endl;
    }
}

/**
  * This function validates the data entered by the user in order to check if the numbers they have entered are more than 0 (because shapes require a positive value)
  * @param num1 The num1 variable is either the height or the length of the shape
  * @param num2 The num2 variable is either the height or the length of the shape
  * @return It will return <code>true</code> if both the numbers are >0 and <code>false</code> if either number is <0
 */
bool dataValidation(const int num1, const int num2) {
    assert(num1 > 0 && num2 > 0);
    
    if(num1 > 0 && num2 > 0) return true;
    
    return false;
}

/**
  * Generate random numbers and get a random shape with a random width (and height), with a random character, numShapes number of times. For each shapeType call the correct function using a switch statement.
  * @param numShapes The numShapes variable is the amount of random shapes that gets generated in the main function
 */
void drawShapes(const int numShapes) {
    assert(numShapes > 0 && numShapes <= 10);
    
    // ShapeType: Generate a number from 0 to 5 and add 1 (so range will become 1-6)
    // ShapeLength && ShapeHeight: Have an offset of 5 and generate a random number between 0-15. Range will become 5-20
    // ShapeCharacter: Have an offset of 33 and generate a random number between 0 and 93
    
    for(int i = 0; i < numShapes; i++) {
        int shapeType = rand() % 6 + 1, shapeLength = 5 + ( rand() % 16 ), shapeHeight = 5 + ( rand() % 16 ), shapeCharacter = 33 + ( rand() % 94 );
        
        switch(shapeType) {
            case 1:
                drawHorizontalLine(shapeLength, shapeCharacter);
                
                break;
            case 2:
                drawVerticalLine(shapeLength, shapeCharacter);
                
                break;
            case 3:
                drawSquareFilled(shapeLength, shapeCharacter);
                
                break;
            case 4:
                drawSquare(shapeLength, shapeCharacter, true);
                
                break;
            case 5:
                drawRectangle(shapeHeight, shapeLength, shapeCharacter, true);
                
                break;
            default:
                drawRectangleFilled(shapeHeight, shapeLength, shapeCharacter);
                
                break;
        }
    }
}

/**
 * This function will initialize the arrays with random values
 * @param shapeTy The shapeTy generates a random value from 1-6, arrSize number of times, to indicate which shape type to print
 * @param shapeLen The shapeLen variable generates a random value from 1-20, arrSize number of times, to see the length of the shape
 * @param shapeCh The shapeCh variable generates a random value (ASCII) from 33-126, arrSize number of times, in order to show it as the character of the shape
 * @param arrSize The arrSize variable is a random value between 1-10 that will be the amount of values that will be generated for the arrays
*/
void initializeArrays(int shapeTy[], int shapeLen[], char shapeCh[], const int arrSize) {
    assert(arrSize >= 1 && arrSize <= 10);
    
    for(int i = 0; i < arrSize; i++) {
        shapeTy[i] = rand() % 6 + 1;
        assert(shapeTy[i] >= 1 && shapeTy[i] <= 6);
        
        shapeLen[i] = rand() % 20 + 1;
        assert(shapeLen[i] >= 1 && shapeLen[i] <= 20);
        
        shapeCh[i] = (char)(33 + (rand() % 94));
        assert(shapeCh[i] >= 33 && shapeCh[i] <= 126);
    }
    
    drawArrays(shapeTy, shapeLen, shapeCh, arrSize);
}
