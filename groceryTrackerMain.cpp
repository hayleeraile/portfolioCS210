#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>

#include "groceryTracker.h"
using namespace std;

int main() {
    GroceryTracker tracker; //creates a new class to access the class from header file
    tracker.readInputFile(); //reads our input file
    tracker.backupItemList(); //creates the backup file and outputs the list to it
    tracker.displayMenu(); //displays our menu to the user
    tracker.menuOptions(); //sifts through the menu options and produces output as told

    return 0;
}