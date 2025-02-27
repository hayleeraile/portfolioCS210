#pragma once
#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>

using namespace std;

class GroceryTracker {
public:
    void readInputFile(); //creates our file read in function
    void backupItemList(); //creates our output file where we write the list of items for backup
    int searchItemFrequency(const string& item); //function that searches for specific items and returns their frequencies
    void printItemFrequencies(); //prints item frequency list
    void printHistogram(); //prints item frequency list along with histogram
    void displayMenu(); //user menu function
    void menuOptions(); //menu options
private:
    map<string, int> itemFrequency; //histogram map for implementation

};
#endif // !groceryTracker_H

