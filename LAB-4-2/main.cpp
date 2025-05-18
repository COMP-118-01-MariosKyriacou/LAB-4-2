/**
 * \file main.cpp
 * \brief Main application with menu
 * \details In this file, there is the main application where it asks the user for inputs and calls the appropriate function for each input. There is also checks ran in this file in order to ensure proper work flow
 * \author Marios Kyriacou (U244N0037)
 * \date 2025
 * \version 0.1
 * \copyright GNU Public License
 */

#include <iostream>
#include <cassert>
#include <cstdlib>
#include "Shapes.h"

using namespace std;

// Global Constants
#define MAX_SHAPES 10

/**
 * We show the menu to the user, get the option that the user wants and then prompt them to enter the desired data
 * @return Returns 0
 */
int main() {
    srand(time(NULL));
    // Variable declarations
    int choice, arrSize, shapeTy[MAX_SHAPES], shapeLen[MAX_SHAPES];
    char character, shapeCh[MAX_SHAPES];
    bool isValid, isActive = true;
    
    // Continuously loop until the user selects to terminate the program
    do {
        // User Option Menu
        cout << "1) Draw a horizontal line" << endl;
        cout << "2) Draw a vertical line" << endl;
        cout << "3) Draw a square" << endl;
        cout << "4) Draw a rectangle" << endl;
        cout << "5) Draw random shapes" << endl;
        cout << "6) Random Shapes (w/ 2 functions)" << endl;
        cout << "7) Quit" << endl;
        
        // Prompt user to enter a choice
        cout << "Enter your option: ";
        cin >> choice;
        
        // Data validation from user. If it isn't valid prompt them to enter a choice until it is valid
        while(choice > 7 || choice < 1) {
            cout << "I need a choice between 1 and 6. If you want to quit enter 7: ";
            cin >> choice;
        }
        
        assert(choice <= 7 && choice >= 1);
        
        // Switch function to choose the correct choice
        switch(choice) {
            // If the choice is 1 through 3, get the size and the character and validate the size so it's positive
            // if it isn't, request a positive number until one is entered.
            case 1:
            case 2:
            case 3:
                // Temporary variable declarations
                int size;
                
                // Prompt user to enter the size and the character
                cout << "Enter the size and the character you want the shape to be: ";
                cin >> size >> character;
                
                // Validate the size
                isValid = dataValidation(size, 1);
                
                // If it is not valid request a new number, otherwise run the correct function
                while(!isValid) {
                    cout << "Please enter a size that is positive! ";
                    cin >> size;
                    
                    // Validate size again
                    isValid = dataValidation(size, 1);
                }
                
                // Run the corresponding function
                if(isValid) {
                    if(choice == 1) drawHorizontalLine(size, character);
                    if(choice == 2) drawVerticalLine(size, character);
                    if(choice == 3) drawSquare(size, character, false);
                }
                
                break;
            case 4:
                int width, height;
                
                cout << "Enter the width, height and the character you want the shape to be: ";
                cin >> width >> height >> character;
                
                isValid = dataValidation(width, height);
                
                // If it is not valid request a new number, otherwise run the correct function
                while(!isValid) {
                    cout << "Please enter a width and height that is positive! ";
                    cin >> width >> height;
                    
                    // Validate size again
                    isValid = dataValidation(width, height);
                }
                
                // Run the corresponding function
                if(isValid) {
                    drawRectangle(width, height, character, false);
                }
                
                break;
            // Draw a random amount (between 1 and MAX_SHAPES) of random shapes
            case 5:
                drawShapes(rand() % MAX_SHAPES + 1);
                
                break;
            // Call the initializeArray() function and pass the arrSize function
            case 6:
                // Random number from 1-10
                arrSize = rand() % 10 + 1;
                
                initializeArrays(shapeTy, shapeLen, shapeCh, arrSize);
                
                break;
            // If they want to exit it breaks automatically and shows "Have a good day!"
            case 7:
            default:
                isActive = false;
                break;
        }
    } while(isActive);
    
    cout << "Have a good day!" << endl;
    
    return 0;
}
