// ItemFrequenc.h
#ifndef ITEM_FREQUENCY_H
#define ITEM_FREQUENCY_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

class ItemFrequency {
//  The class helps define functions to be called upon by the program
//  The public members are written to be called upon and be editable based on the input.
public:
    ItemFrequency(const string& input_file);
    int searchItemFrequency(const string& item);
    void printAllItemFrequencies();
    void printHistogram();
    void createBackupFile(const string& backup_file);

// The private class cannot be change by the user
private:
    map<string, int> item_map;
    void populateItemMap(const string& input_file);
};

#endif