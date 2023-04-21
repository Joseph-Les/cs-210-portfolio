/*
Corner Grocer Project
By: Joseph J. Les
04/16/2023
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "ItemFrequency.h"
using namespace std;

// Function to print the menu
void PrintMenu() {
    cout << "Menu:\n";
    cout << "1. Search item frequency\n";
    cout << "2. Print all item frequencies\n";
    cout << "3. Print histogram\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    const string input_file = "CS210_Project_Three_Input_File.txt";
    const string backup_file = "frequency.dat";
    ItemFrequency item_frequency(input_file);
    item_frequency.createBackupFile(backup_file);

    int choice;
    string item;

    do {
        PrintMenu();
        cin >> choice; // stores the user input/selection

        /* the switch case will check the user "choice" with each case number, match it, then the case
        wiil execute the commands. If the "choice" does not match any of the selection, then the deault
        case will be called, outputing an error message for the user.
        */
        switch (choice) {
        case 1:
            cout << "Enter the item name: ";
            cin >> item;
            cout << "Frequency: " << item_frequency.searchItemFrequency(item) << endl;
            cout << endl;
            break;
        case 2:
            item_frequency.printAllItemFrequencies();
            cout << endl;
            break;
        case 3:
            item_frequency.printHistogram();
            cout << endl;
            break;
        case 4:
            cout << "Exiting the program.\n";
            break;
        default:
            cerr << "Invalid option. Please try again.\n";
            break;
        }
    } 
    // when the user selectes 4, the loop will break, the program will end
    while ( choice != 4);{
        return 0;
    }
}