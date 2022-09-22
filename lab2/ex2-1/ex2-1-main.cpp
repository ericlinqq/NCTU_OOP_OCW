// ex2-1-main.cpp
#include <iostream>
#include "ex2-1.h"

using namespace test;

int main(int argc, char* argv[]) {
    Student *list;
    int student_num = ReadTextFile(argv[1], list);
    EvaluateScore(student_num, list);
    PrintScore(argv[2], student_num, list);
    return 0;
}
