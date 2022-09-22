// ex2-1.h
#include <iostream>
#include <string>
#include <vector>

namespace test{
    typedef struct {
        int id;
        std::string name;
        int easy[3];
        int medium[3];
        int hard[3];
        int score;
        int time;
    }Student;
    
    int ReadTextFile(char *argv_1, Student* &list);
    void EvaluateScore(int student_num, Student* &list);
    void PrintScore(char* argv_2, int student_num, Student* &list);
    const std::vector<std::string> split(const std::string &str, const std::string &pattern);
}
