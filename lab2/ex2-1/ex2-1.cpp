// ex2-1.cpp
#include <iostream>
#include "ex2-1.h"
#include <fstream>
#include <string>
#include <vector>

namespace test {
    const std::vector<std::string> split(const std::string &str, const std::string &pattern) {
        std::vector<std::string> result;
        std::string::size_type begin, end;

        end = str.find(pattern);
        begin = 0;

        while (end != std::string::npos) {
            if (end - begin != 0) {
                result.push_back(str.substr(begin, end-begin));
            }

            begin = end + pattern.size();
            end = str.find(pattern, begin);
        }

        if (begin != str.length()) {
            result.push_back(str.substr(begin));
        }

        return result;
    }
    
    int  ReadTextFile(char* argv_1, Student* &list) {
        std::string line;
        int MAX = 10;
        int student_num = 0;
        std::string *line_ptr = new std::string [MAX];
        
        // read file, get lines in the file
        std::ifstream in_file(argv_1);
        if (in_file.fail()) {
            std::cout << "Cannot open the file " << argv_1 << std::endl;
            exit(1);
        }
        else {
            std::cout << "input: " << std::endl;
            while (std::getline(in_file, line)) {
                line_ptr[student_num] = line;
                student_num++;
                std::cout << line << std::endl;

                // expand dynamic array
                if (student_num >= MAX) {
                    std::cout << "(Expanding dynamic array...)" << std::endl;
                    MAX *= 2;
                    std::string *tmp = new std::string [MAX];
                    // copy to tmp
                    for (int j = 0; j < student_num; j++) {
                        tmp[j] = line_ptr[j];
                    }
                    
                    delete  [] line_ptr;
                    line_ptr = tmp;
                }
            }
        }

        // record each student data
        list = new Student[student_num]; 
        for (int i = 0; i < student_num; i++) {
            const std::vector<std::string> line_split = split(line_ptr[i], " ");
            list[i].id = std::stoi(line_split[0]);
            list[i].name = line_split[1];

            for (int j = 2; j < 11; j++) {
                if (j < 5)
                    list[i].easy[j-2] = std::stoi(line_split[j]);
                else if (4 < j < 8)
                    list[i].medium[j-5] = std::stoi(line_split[j]);
                else
                    list[i].hard[j-8] = std::stoi(line_split[j]);
            }

            list[i].time = std::stoi(line_split[11]);
        }

        return student_num;
    }

    void EvaluateScore(int student_num, Student* &list) {
        // calculate score for each student
        for (int i = 0; i < student_num; i++) {
            list[i].score = (list[i].easy[0] + list[i].easy[1] + list[i].easy[2]) * 10 +
                            (list[i].medium[0] + list[i].medium[1] + list[i].medium[2]) * 20 +
                            (list[i].hard[0] + list[i].hard[1] + list[i].hard[2]) * 30;
            if (list[i].score > 100)
                list[i].score = 100;
        }

        // sort the score by descending order
        for (int i = 0; i < student_num; i++) {
            for (int j = i; j < student_num; j++) {
                if (list[i].score < list[j].score || (list[i].score == list[j].score && list[i].time > list[j].time)) {
                    Student temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }
    }

    void PrintScore(char* argv_2, int student_num, Student* &list) {
        // write file 
        std::ofstream out_file(argv_2, std::ios::out | std::ios::trunc);
        
        if (out_file.fail()) {
            std::cout << "Error" << std::endl;
            exit(1);
        }
        else {
            std::cout << "output: " << std::endl;
            for (int i = 0; i < student_num; i++) {
                if (list[i].id < 10) {
                    std::cout << "0" << list[i].id << " ";
                    out_file << "0" << list[i].id << " ";
                }
                else {
                    std::cout << list[i].id << " ";
                    out_file << list[i].id << " ";
                }
                std::cout << list[i].name << " " << list[i].score << " " << list[i].time << std::endl;
                out_file << list[i].name << " " << list[i].score << " " << list[i].time << std::endl;
            }
        }
    }
}
