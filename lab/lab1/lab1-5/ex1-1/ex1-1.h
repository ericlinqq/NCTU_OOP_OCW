// ex1-1.h
namespace Complex {
    typedef struct{
        double real;
        double image;
    }Cplex;

    const double pi = 3.1416;
    void ReadTextFile(char *argv_1, Cplex &a, Cplex &b);
    Cplex ComplexOperation(const Cplex &a, const Cplex &b, char op);
    void PrintComplex(char *argv_2, const Cplex *results);
}