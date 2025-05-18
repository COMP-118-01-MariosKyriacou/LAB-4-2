/**
 * \file main.cpp
 * \brief Prompt menu to user and run action
 * \details In this program, we prompt a user to select an option from a menu and then we find the proper action through a switch statement. There is also data validation checks in order to ensure that there won't be a non-valid option selection
 * \author Marios Kyriacou (U244N0037)
 * \date 2025
 * \version 0.1
 * \copyright GNU Public License
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <array>
#include "Matrix.h"
#include "namespaces.h"

#define ROWS 3

/**
 * Prompt user a menu in order to select which option they'd like and then select the appropriate action using a switch statement
 * @return Returns 0
 */
int main() {
    // Seed random number generator
    srand(time(0));
    
    // Variable declarations
    double matrix[ROWS][Globals::MAX_COL], transposed[ROWS][Globals::MAX_COL];
    int option, tempOption;
    
    do {
        // Menu for selections
        std::cout << "1) Fill Matrix with Values" << std::endl;
        std::cout << "2) Fill Matrix with Random Values" << std::endl;
        std::cout << "3) Find the Sum of a Specific Row" << std::endl;
        std::cout << "4) Find the Sum of a Specific Column" << std::endl;
        std::cout << "5) Display Matrix" << std::endl;
        std::cout << "6) Get the biggest value within the Matrix" << std::endl;
        std::cout << "7) Get the transposed matrix" << std::endl;
        std::cout << "8) Get the average of the elements within the matrix" << std::endl;
        std::cout << "9) Exit" << std::endl;
        
        // Prompt user to select option
        std::cout << "Enter which option you'd like: ";
        std::cin >> option;
        
        // Data validation
        while(option < 1 || option > 9) {
            std::cout << "Please enter an option between 1 and 9: ";
            std::cin >> option;
        }
        
        // Select proper option
        switch(option) {
            case 1:
                for(int i = 0; i < ROWS; i++) {
                    for(int j = 0; j < Globals::MAX_COL; j++) {
                        std::cin >> matrix[i][j];
                    }
                }
                break;
            case 2:
                fillWithRandomNum(matrix, ROWS);
                std::cout << "Matrix has been filled. " << std::endl;
                break;
            case 3:
                std::cout << "Which row would you like to find the sum of? ";
                std::cin >> tempOption;
                
                while(tempOption < 0 || tempOption > ROWS - 1) {
                    std::cout << "Please provide a row between 0 and " << ROWS - 1 << ": ";
                    std::cin >> tempOption;
                }
                
                std::cout << "Sum of row " << tempOption << " is: " << sumOfRow(matrix, tempOption, ROWS) << std::endl;
                
                break;
            case 4:
                std::cout << "Which column would you like to find the sum of? ";
                std::cin >> tempOption;
                
                while(tempOption < 0 || tempOption > ROWS - 1) {
                    std::cout << "Please provide a column between 0 and " << Globals::MAX_COL - 1 << ": ";
                    std::cin >> tempOption;
                }
                
                std::cout << "Sum of column " << tempOption << " is: " << sumOfCol(matrix, tempOption, ROWS) << std::endl;
                
                break;
            case 5:
                printMatrix(matrix, ROWS);
                break;
            case 6:
                std::cout << "Maximum value in the matrix: " << maximumValue(matrix, ROWS) << std::endl;
                break;
            case 7:
                transposedMatrix(matrix, transposed, ROWS);
                printMatrix(transposed, ROWS);
                break;
            case 8:
                std::cout << "The average of all the elements combined is: " << averageOfElements(matrix, ROWS) << std::endl;
                break;
            case 9:
            default:
                break;
        }
    } while(option != 9);
    
    return 0;
}
