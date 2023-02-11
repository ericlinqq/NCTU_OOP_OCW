// ex1-1.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "ex1-1.h"

namespace Complex {
    void ReadTextFile(char *argv_1, Cplex &a, Cplex &b)
    {
        std::cout << "argv[1] = " << argv_1 << std::endl;

        //read file
        std::ifstream in_file(argv_1);
        std::string input[2];

        if (in_file.fail()) {
            std::cout << "Cannot open the file" << argv_1 << std::endl;
        }
        else {
            std::getline(in_file, input[0]);
            std::getline(in_file, input[1]);
            std::cout << "num1 = " << input[0] << std::endl;
            std::cout << "num2 = " << input[1] << std::endl;
            in_file.close();
        }

        // find specific character
        std::string num_re[2], num_im[2];
        int op_1, op_2;

        for (int i = 0; i < 2; i++) {        // input[0], input[1]
            for (int j = 1; j < input[i].length(); j++) {        // find + or - in the middle
                if (input[i].at(j) == '+' || input[i].at(j) == '-') {
                    op_1 = j;
                }
                else if (input[i].at(j) == 'i') {       // find i
                    op_2 = j;
                }
            }

            num_re[i] = input[i].substr(0, op_1);
            if (input[i].at(op_1) == '-') {        // keep the minus sign
                num_im[i] = input[i].substr(op_1, op_2 - op_1); 
            }
            else if (input[i].at(op_1) == '+') {
                num_im[i] = input[i].substr(op_1+1, op_2 - op_1 + 1);
            }
        }

        a.real = std::stod(num_re[0]);
        a.image = std::stod(num_im[0]);
        b.real = std::stod(num_re[1]);
        b.image = std::stod(num_im[1]);

        std::cout << "num1 real = " << a.real << ", image = " << a.image << std::endl;
        std::cout << "num2 real = " << b.real << ", image = " << b.image << std::endl;
    }

    Cplex ComplexOperation(const Cplex &a, const Cplex &b, char op) {
        Cplex r;
        if (op == '+') {
            r.real = a.real + b.real;
            r.image = a.image + b.image;
        }
        else if (op == '-') {
            r.real = a.real - b.real;
            r.image = a.image - b.image;
        }
        else if (op == '*') {
            r.real = (a.real * b.real) - (a.image * b.image);
            r.image = (a.image * b.real) + (a.real * b.image); 
        }
        else if (op == '/') {
            r.real = ((a.real * b.real) + (a.image * a.image)) / ((b.real * b.real) + (b.image * b.image));
            r.image = ((a.image * b.real) - (a.real * b.image)) / ((b.real * b.real) + (b.image * b.image));
        }
        else {
            std::cout << "Error" << std::endl;
        }

        return r;
    }

    void PrintComplex(char *argv_2, const Cplex *results) {
        std::cout << "argv[2] = " << argv_2 << std::endl;

        // write file
        std::ofstream out_file(argv_2);

        if (out_file.fail()) {
            std::cout << "Cannot open the file" << argv_2 << std::endl;
        }
        else {
            for (int i = 0; i < 4; i++) { // +, - , *, /
                if (results[i].image < 0) {
                    out_file << std::setprecision(3) << results[i].real << "-" << results[i].image * (-1) << "i" << std::endl;
                }
                else {
                    out_file << std::setprecision(3) << results[i].real << "+" << results[i].image << "i" << std::endl;
                }
            }
        }

        std::cout << std::setprecision(3) << results[0].real << "," << results[0].image << std::endl;
        std::cout << std::setprecision(3) << results[1].real << "," << results[1].image << std::endl;
        std::cout << std::setprecision(3) << results[2].real << "," << results[2].image << std::endl;
        std::cout << std::setprecision(3) << results[3].real << "," << results[3].image << std::endl;
    }
}