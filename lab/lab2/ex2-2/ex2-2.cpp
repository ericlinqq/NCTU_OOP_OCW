// ex2-2.cpp
#include <iostream>
#include <fstream>

typedef struct {
    int *data;
    int length;
    bool sign;
}BIGNUMBER;

void ReadTextFile(char *argv_1, BIGNUMBER &a, BIGNUMBER &b);
BIGNUMBER BigNumberOperation(BIGNUMBER a, BIGNUMBER b, char op);
void WriteResults(char *argv_2, BIGNUMBER *results);

int main(int argc, char *argv[]) {
    BIGNUMBER a, b;
    ReadTextFile(argv[1], a, b);

    BIGNUMBER results[2];

    results[0] = BigNumberOperation(a, b, '+');
    results[1] = BigNumberOperation(a, b, '-');
    
    WriteResults(argv[2], results);


    return 0;
}

void ReadTextFile(char *argv_1, BIGNUMBER &a, BIGNUMBER &b) {
    std::ifstream in_file(argv_1);
    std::string line[2];

    if (in_file.fail()) {
        std::cout << "Cannot open the file " << argv_1 << std::endl;
    }
    else {
        std::cout << "input: " << std::endl;
        int i = 0;
        while (std::getline(in_file, line[i])) {
            std::cout << line[i] << std::endl;
            i++;
            if (i > 1) break;
        }
    }

    a.sign = (line[0].at(0) == '-')? 1: 0;
    if (a.sign) {
        a.length = line[0].length()-1;
        a.data = new int[a.length];
        for (int i = a.length-1; i >= 0; i--) {
            a.data[i] = line[0].at(i+1) - '0';
        }
    }
    else {
        a.length = line[0].length();
        a.data = new int[a.length];
        for (int i = a.length-1; i >= 0; i--) {
            a.data[i] = line[0].at(i) - '0';
        }
    }

    b.sign = (line[1].at(0) == '-')? 1: 0;
    if (b.sign) {
        b.length = line[1].length()-1;
        b.data = new int[b.length];
        for (int i = b.length-1; i >= 0; i--) {
            b.data[i] = line[1].at(i+1) - '0';
        }
    } 
    else {
        b.length = line[1].length();
        b.data = new int[b.length];
        for (int i = b.length-1; i >= 0; i--) {
            b.data[i] = line[1].at(i) - '0';
        }
    }
}

BIGNUMBER BigNumberOperation(BIGNUMBER a, BIGNUMBER b, char op) {
    std::cout << "Big number operation" << std::endl;

    // create new int* to save the results
    int *a_ptr = a.data;
    int *b_ptr = b.data;
    
    // create a new int array, in order not to overwrite the original memory
    a.data = new int[a.length];
    b.data = new int[b.length];

    for (int i = 0; i < a.length; i++) {
        a.data[i] = a_ptr[i];
    }
 
    for (int i = 0; i < b.length; i++) {
        b.data[i] = b_ptr[i];
    }
    
    // a - b = a + (-b)
    if (op == '-') {
        if (b.sign)
            b.sign = 0;
        else
            b.sign = 1;
    }
    
    // make sure a.length >= b.length
    if (a.length < b.length) {
        BIGNUMBER tmp = a;
        a = b;
        b = tmp;
    }

    // plus 
    if (a.sign == b.sign) {     // (+) + (+) or (-) + (-)
        // add
        for (int i = 0; i < b.length; i++) {
            a.data[a.length-1-i] += b.data[b.length-1-i];
        }
        
        // check overflow
        for (int i = a.length-1; i > 0; i--) {
            if (a.data[i] >= 10) {
                a.data[i] -= 10;
                a.data[i-1]++;
            }
        }

        // first digit overflow -> enlarge the array
        if (a.data[0] >= 10) {
            int* tmp = a.data;
            a.length++;
            a.data = new int[a.length];
            for (int i = a.length-1; i > 0; i++) {
                a.data[i] = tmp[i-1];
            }

            a.data[1] -= 10;
            a.data[0] = 1;
        }     
    }
    else {      // (+) + (-) or (-) + (+)
        // add 
        for (int i = 0; i < b.length; i++) {
            a.data[a.length-1-i] -= b.data[b.length-1-i];
        }

        // check underflow
        for (int i = a.length-1; i > 0; i--) {
            if (a.data[i] < 0) {
                int x = 0;
                while (a.data[i-x] > 0) {
                    a.data[i-x]--;
                    for (int j = x-1; j > 0; j--) {
                        a.data[i-j] += 9;
                    }
                    a.data[i] += 10;
                    x++;
                    break;
                }
            }
        }
    }    

    return a; 
}

void WriteResults(char *argv_2, BIGNUMBER *results) {
    // write file
    std::cout << "Write results" << std::endl;
    std::ofstream out_file(argv_2);
    if (out_file.fail()) {
        std::cout << "Error" << std::endl;
        exit(1);
    }
    else {
        int first_nonzero;
        // add
        std::cout << "A + B = ";
        out_file << "A + B = ";
        if (results[0].sign)
            std::cout << "-";
            out_file << "-";

        for (int i = 0; i < results[0].length; i++) {
            if (results[0].data[i] != 0)  {
                first_nonzero = i;
                break;
            }
        }

        for (int i = first_nonzero; i < results[0].length; i++) {
            std::cout << results[0].data[i];
            out_file << results[0].data[i];
        }
        std::cout << std::endl;
        out_file << std::endl;

        // subtract
        std::cout << "A - B = ";
        out_file << "A - B = ";
        if (results[1].sign)
            std::cout << "-";
            out_file << "-";

        for (int i = 0; i < results[1].length; i++) {
            if (results[1].data[i] != 0) {
                first_nonzero = i;
                break;
            }
        }

        for (int i = first_nonzero; i < results[1].length; i++) {
            std::cout << results[1].data[i];
            out_file << results[1].data[i];
        }
        std::cout << std::endl;
        out_file << std::endl;
    }
    
    delete [] results[0].data;
    delete [] results[1].data;
    
    results = NULL;
}
