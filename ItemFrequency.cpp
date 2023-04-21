// Header file to call upon the class ItemFrequency
#include "ItemFrequency.h"

// populateItemMap will read the given input file and
// populate the item_map data member with the frequency count of each item
ItemFrequency::ItemFrequency(const string& input_file) {
    populateItemMap(input_file);
}

/*
    This function will take a constant reference to string name input_file/
    Creates an input file stream object and creates a string variable.
    If the file is able to open, while loop will read each line one at a time,
    comparing it to item, and icrementing it by 1, untilend of file, then closes file.
*/
void ItemFrequency::populateItemMap(const string& input_file) {
    ifstream in_file(input_file);
    string item;

    if (in_file.is_open()) {
        while (in_file >> item) {
            item_map[item]++;
        }
        in_file.close();
    }
    else {
        cerr << "Error: Unable to open input file." << endl;
    }
}

// Function will return the value of item_map
int ItemFrequency::searchItemFrequency(const string& item) {
    return item_map[item];
}

// This function defines the printAllItemFrequencies.
// The loop will iterate over all elements, print key pairs, and print their frequency
void ItemFrequency::printAllItemFrequencies() {
    for (const auto& entry : item_map) {
        cout << entry.first << " " << entry.second << endl;
    }
}

// This function will loop throughall elements, print the key pairs, and print their frequency
// using a ' * ' instead of a number.
void ItemFrequency::printHistogram() {
    for (const auto& entry : item_map) {
        cout << entry.first << " " << string(entry.second, '*') << endl;
    }
}

/*
    The function purpose is to create a backup file containing the frequency count of all items.
    First the if statement check if the file can open/created.
    Next the for loop with iterate through each item, print it, then print the count next to it.
    What the for loop is done, the file will be closed. If the file was not open, and error 
    message will be printed.
*/
void ItemFrequency::createBackupFile(const string& backup_file) {
    ofstream out_file(backup_file);
    if (out_file.is_open()) {
        for (const auto& entry : item_map) {
            out_file << entry.first << " " << entry.second << endl;
        }
        out_file.close();
    }
    else {
        cerr << "Error: Unable to create backup file." << endl;
    }
};
