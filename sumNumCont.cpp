// Copyright (c) Marcus Wehbi All rights reserved.
//
// Created by: Marcus Wehbi
// Date: Nov 10 2022
// This program asks the user how many numbers they would like
// to add.It then uses a while loop to calculate and display
// the sum of the numbers they inputted.
// This program uses a continue statement.

#include <iostream>

int main() {
    // initialize counter, and the sum of the numbers
    int counter = 0;
    int sum = 0;
    // declare number and string variables
    // First input - how many numbers they want to add
    int userNumAInt;
    float userFloatAInt;
    // Following inputs - all the numbers to add
    int userNumBInt;
    float userFloatBInt;
    // Get the numbers as strings
    std::string userNumAString;
    std::string userNumBString;
    // String to output the final sum
    std::string answer;

    while (true) {
        // get user number as a string
        std::cout << "How many numbers would you like to add?: ";
        std::cin >> userNumAString;
        std::cout << std::endl;

        try {
            // converts the first user input to an integer
            userNumAInt = stoi(userNumAString);
            // converts the first user input to a float
            userFloatAInt = stof(userNumAString);

            // Make sure the user does not enter decimals
            if (userNumAInt != userFloatAInt) {
                std::cout << "Please enter a whole number!\n"
                << std::endl;
            } else {
                    // Make sure the first input is greater than or equal to 0
                    if (userNumAInt >= 0) {
                        // calculate the sum of the entered numbers
                        while (counter < userNumAInt) {
                            // Get each number to add
                            std::cout << "Enter a whole number: ";
                            std::cin >> userNumBString;

                            try {
                                // converts entered number from string
                                // to integer
                                userNumBInt = stoi(userNumBString);
                                // converts the first user input to a float
                                userFloatBInt = stof(userNumBString);
                                // User enters a negative number
                                if (userNumBInt != userFloatBInt) {
                                    std::cout
                                    << "Please enter a whole number!\n"
                                    << std::endl;
                                    continue;
                                }
                                // Make sure they do not enter a negative number
                                if (userNumBInt < 0) {
                                    std::cout << userNumBInt;
                                    std::cout
                                    << " is negative and cannot be added\n";
                                    std::cout << std::endl;
                                    // Go back to the top of the loop
                                    continue;
                                }
                                // Add the number to the sum
                                std::cout << userNumBInt
                                << " added to the sum.\n";
                                std::cout << std::endl;
                                // Update the sum
                                sum = sum + userNumBInt;
                                // Increment the counter by 1
                                counter = counter + 1;
                                // Update string
                                answer += userNumBString + " + ";
                            } catch (std::invalid_argument) {
                                // The user did not enter a number.
                                std::cout << userNumBString
                                << " is not a number.\n";
                                std::cout << std::endl;
                                // Go to top of loop
                                continue;
                            }
                        }
                        if (counter == userNumAInt) {
                            // Once you have reached the amount of numbers
                            // they wanted
                            // to input, display the final sum
                            std::cout << answer << "0"
                                    << " = " << sum;
                            std::cout << std::endl;
                            std::cout << "The sum is " << sum << ".";
                            // Exit the loop
                            break;
                        }
                    } else {
                        std::cout << "Please enter a whole number!\n";
                        std::cout << std::endl;
                    }
                    // determines if the the answer is a number
                }
        } catch (std::invalid_argument) {
            // The user did not enter a number.
            std::cout << userNumAString << " is not a number.\n";
            std::cout << std::endl;
        }
    }
}
