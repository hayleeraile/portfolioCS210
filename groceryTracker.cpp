#include "groceryTracker.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <algorithm> //used in conjunction with transform. this helps with input validation with upper/lower case letters
using namespace std;

void GroceryTracker::readInputFile() { //this reads in the file that was given to us
    ifstream inputFile("CS210_Project_Three_Input_File.txt"); //the file that is being read in
    if (!inputFile.is_open()) { //if the file won't open, an error message will be printed
        cout << "Error: Unable to open file " << endl; //error message
        return;
    }
    string item; //creating a variable for the items in the list
    
    while (inputFile >> item) { //we can read through each item one by one
        transform(item.begin(), item.end(), item.begin(), ::tolower); //this transforms the items into lower case to help with input validations
        itemFrequency[item]++; //everytime the same item is read, the count increments
    }
    
    inputFile.close(); //after reading through line by line, we close the file
}

//This function creates our output file
void GroceryTracker::backupItemList() {
    ofstream outputFile("frequency.dat"); //file to be created
    if (!outputFile.is_open()) { //if the file cannot open, an error message is thrown
        cout << "Error: Unable to create backup file 'frequency.dat' " << endl; //error message
        return;
    }

    for (const auto& items : itemFrequency) { //uses const auto& because we just want to read each item, not edit them
        outputFile << items.first << " " << items.second << endl; //uses .first and .second to print the item and their frequencies
    }
    outputFile.close(); //after reading through each line, the file closes
}

// This funcction prints the frequency of each item on the list
int GroceryTracker::searchItemFrequency(const string& item) {
    auto itemNumber = itemFrequency.find(item); //we use auto because the compiler can decide the correct type for the variable based on entering the map. this looks for the item in the map
    if (itemNumber != itemFrequency.end()) { //if the item is found, the item and its frequency are printed
        return itemFrequency[item];
    }
    else { //if they are not, an error is printed and a -1 is returned. we use the negative one in the menuOptions function
        cout << "Item not found in list!" << endl;
        return -1;
    }
}

// This function prints a list of all the items and prints their frequency next to the item
void GroceryTracker::printItemFrequencies() {
    for (const auto& items : itemFrequency) { //we use const auto& because we want to access the items in the range, but only need to read them not edit them
        cout << items.first << " " << items.second << endl; //using .first prints the words and .second prints the frequency of that word. 
    }
}

// This function prints the list of all of the items and uses their frequency to create a histogram
void GroceryTracker::printHistogram() {
    for (const auto& items : itemFrequency) { //same as above, we use const auto& because we just want to read the items in the range, not edit them. 
        cout << items.first << " "; //this prints out the item using the .first
        for (int i = 0; i < items.second; ++i) { //because we didn't use endl; the for loop starts at 0 and goes until the length of the frequency to print out however many stars. this creates our histogram
            cout << "*";
        }
        cout << endl;
    }
}

//This function prints the menu that displays the options for the user to pick from
void GroceryTracker::displayMenu() { 
    cout << "Menu Options:                    " << endl;
    cout << "1. Search for item frequency     " << endl;
    cout << "2. Print item frequency list     " << endl;
    cout << "3. Print item frequency histogram" << endl;
    cout << "4. Exit the program              " << endl;
    cout << "Enter an option 1-4:             " << endl;
}

void GroceryTracker::menuOptions() { //this function goes into more detail for the menu options
    int userChoice; // variable for the number choice
    string item; //variable for the item input in option one
    
    do { //do-while loop runs while the userChoice is not equal to 4
        cin >> userChoice; //user inputs the menu option they want

        if (cin.fail()) { //input validation for anything other than 1-4
            cin.clear(); //clears the input
            cin.get(); //refreshes the screen
            cout << "Invalid input!" << endl; //error message
        }

        switch (userChoice) { //switch statement for the different user choices
        case 1: //option one prints the chosen item and its frequency
            cout << "Enter the item you wish to search for: ";
            cin >> item; //user enters the item they are looking for
            transform(item.begin(), item.end(), item.begin(), ::tolower); //transforms the input to lower case for easy input validation
            
            if (GroceryTracker::searchItemFrequency(item) != -1) { //if the item was not found in our searchItemFrequency function, it wont print other than the error message. if it was found, the item and frequency are printed.
                cout << item << " " << GroceryTracker::searchItemFrequency(item) << endl; //prints the item and then uses the search function to find that item and print out the frequency
                cout << endl;
            }
            GroceryTracker::displayMenu(); //displays the menu for the next option
            break;
        case 2: //option two prints a list of all items and their frequencies
            GroceryTracker::printItemFrequencies();
            cout << endl;
            GroceryTracker::displayMenu(); //displays menu for the next option
            break;
        case 3: //option three prints a list of all items and prints their frequencies in a histogram
            GroceryTracker::printHistogram();
            cout << endl;
            GroceryTracker::displayMenu(); //displays menu for the next option
            break;
        case 4: //option four exits the program if selected
            cout << "Exiting the program . . ." << endl;
            break;
        default: //if anything other than 1-4 is picked, an error message is printed
            cout << "Must enter a number between 1 and 4!" << endl;
            cout << endl;
            GroceryTracker::displayMenu(); //displays menu for th enext option
            break;
        }
    } while (userChoice != 4);
}