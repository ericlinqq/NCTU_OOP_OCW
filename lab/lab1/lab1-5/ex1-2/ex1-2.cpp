// ex1-2.cpp
#include <iostream>
#include <fstream>
#include <string>

const int MAX = 1000;

typedef struct
{
    double coeff;
    int power;
}Items;

typedef struct
{
    Items items[MAX];
    int num_items;
}Poly;

// Declaration
void ReadTextFile(char *argv_1, Poly &eq);
void DifferentationPoly(Poly &eq);
void PrintComplex(char *argv_2, Poly &eq);

int main(int argc, char *argv[]) {
    Poly eq;
    ReadTextFile(argv[1], eq);  // process text file
    DifferentationPoly(eq); // differentation of polynomials
    PrintComplex(argv[2], eq);  // print the results on file
    return 0;
}

// Definition
void ReadTextFile(char *argv_1, Poly &eq) {
    std::cout << "Input file: " << argv_1 << std::endl;

    std::string input;
    std::string item_string[MAX];
    // Read file
    std::ifstream in_file(argv_1);
    if (in_file.fail()) {
        std::cout << "Cannot open the file " << argv_1 << std::endl;
    }
    else {
        std::getline(in_file, input);
        std::cout << "input = " << input << std::endl;
    }

    // Parsing text
    int j = 0;
    eq.num_items = 0;
    for (int i = 1; i < input.length(); i++) {
        if (input.at(i) == '+' || input.at(i) == '-') {
            item_string[eq.num_items] = input.substr(j, i-j);
            eq.num_items++;
            j = i;
        }
    }

    item_string[eq.num_items] = input.substr(j, input.length()-j);  // The last item
    eq.num_items++;
    
    // parsing individual text item
    for (int i = 0; i < eq.num_items; i++) {
        int found = item_string[i].find("X");
        if (item_string[i].find("X") == std::string::npos) {  // NO "X" in the item, which is a CONSTANT
            // coefficient
            eq.items[i].coeff = std::stof(item_string[i]);
            // power 
            eq.items[i].power = 0;
        }
        else {
            // coefficient
            if (item_string[i].substr(0, found) == "+") {
                eq.items[i].coeff = 1;
            }
            else { 
                eq.items[i].coeff = std::stof(item_string[i].substr(0, found));
            }
            // power
            if (item_string[i].length() == found+1) {
                eq.items[i].power = 1;
            }
            else {
                std::string tmp = item_string[i].substr(found+2, item_string[i].length()-found-2);
                eq.items[i].power = std::stoi(tmp);
            }
        }
    }

    // Sort
    std::cout << "Sort" << std::endl;
    for (int i = 0; i < eq.num_items; i++) {
        for (int j=i+1; j < eq.num_items; j++) {
            if (eq.items[i].power < eq.items[j].power) {
                // swap
                int tmp_power = eq.items[j].power;
                double tmp_coeff = eq.items[j].coeff;
                eq.items[j].power = eq.items[i].power;
                eq.items[j].coeff = eq.items[i].coeff;
                eq.items[i].power = tmp_power;
                eq.items[i].coeff = tmp_coeff;
            }
        }
    }
}

void DifferentationPoly(Poly &eq) {
    std::cout << "Diff" << std::endl;
    for (int i = 0; i < eq.num_items; i++) {
        if (eq.items[i].power != 0) {
            eq.items[i].coeff *= eq.items[i].power;
            eq.items[i].power--;
        }
        else {
            eq.items[i].power = 0;
            eq.items[i].coeff = 0;
            eq.num_items--;
        }
    }
}

void PrintComplex(char *argv_2, Poly &eq) {
    // write file
    std::ofstream out_file(argv_2, std::ios::out | std::ios::trunc);

    if (out_file.fail()) {
        std::cout << "Cannot open the file " << argv_2 << std::endl;
    }
    else {
        for (int i = 0; i < eq.num_items; i++) {
            if (eq.items[i].coeff > 0) {
                if (i != 0) {
                    out_file << "+";
                }
                if (eq.items[i].power == 0)
                    out_file << eq.items[i].coeff;
                else if (eq.items[i].power == 1)
                    out_file << eq.items[i].coeff << "X";
                else
                    out_file << eq.items[i].coeff << "X^" << eq.items[i].power;    
            }
            else if (eq.items[i].coeff < 0) {
                if (eq.items[i].power == 0)
                    out_file << eq.items[i].coeff;
                else if (eq.items[i].power == 1)
                    out_file << eq.items[i].coeff << "X";
                else
                    out_file << eq.items[i].coeff << "X^" << eq.items[i].power;  
            }
        }
    }
}

