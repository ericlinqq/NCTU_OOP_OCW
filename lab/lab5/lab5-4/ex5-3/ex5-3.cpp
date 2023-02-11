// ex5-3.cpp
#include <iostream>
#include "Vec.h"
using std::cout;
using std::endl;
using std::cin;

int main() {
    int MAX_SIZE = 5;
    int *array1 = new int[MAX_SIZE]{0}, *array2 = new int[MAX_SIZE]{0};
    int dim1 = 0, dim2 = 0;
    int input;

    /* read numbers from screen for array1 and array2   */
    /* enter -1 to end input                            */
    /* return the dimension of each array               */
    cout << "Enter the elements for array (-1 to end):" << endl;
    while(1) {
        cin >> input;
        if (input == -1)
            break;
        else
            array1[dim1] = input;
            dim1++;
        if (dim1 >= MAX_SIZE) {
            MAX_SIZE += 5; 
            int *tmp = new int[MAX_SIZE]{0};
            for (int i = 0; i < dim1; i++) {
                tmp[i] = array1[i];
            }
            delete [] array1;
            array1 = tmp;
            tmp = NULL;
        }
    }  

    int* tmp = new int[dim1]{0};
    for (int i = 0; i < dim1; i++) {
        tmp[i] = array1[i];
    }
    delete [] array1;
    array1 = tmp;
    tmp = NULL;

    MAX_SIZE = 5;
    cout << "Enter the elements for array (-1 to  end):" << endl;
    while(1) {
        cin >> input;
        if (input == -1)
            break;
        else
            array2[dim2] = input;
        dim2++;
        if (dim2 >= MAX_SIZE) {
            MAX_SIZE += 5; 
            int *tmp = new int[MAX_SIZE]{0};
            for (int i = 0; i < dim2; i++) {
                tmp[i] = array2[i];
            }
            delete [] array2;
            array2 = tmp;
            tmp = NULL;
          
        }

    }

    tmp = new int[dim2]{0};
    for (int i = 0; i < dim2; i++) {
        tmp[i] = array2[i];
    }
    delete [] array2;
    array2 = tmp;
    tmp = NULL;

    Vec vec1(array1, dim1);
    Vec vec2;
    vec2.assign(array2, dim2);

    cout << "vec1(sorted): ";
    vec1.sort();
    vec1.printVec();

    cout << "vec2(sorted): ";
    vec2.sort();
    vec2.printVec();

    bool isEqual = vec1.isEqual(vec2);
    
    /* print out the message if vec1 and vec2 are the same or not*/
    if (isEqual)
        cout << "vec1 is equal to vec2" << endl;
    else
        cout << "vec1 is not equal to vec2" << endl;

    Vec vec3;
    vec3.unionSet(vec1, vec2); // vec3 is union set of vec1 and vec2
    
    cout << "vec3: ";
    vec3.printVec();
    
    vec3.sort();
    cout << "vec3(sorted): ";
    vec3.printVec();

    cout << "Min in vec1 and vec2: " << vec3.min() << endl;
    cout << "Max in vec1 and vec2: " << vec3.max() << endl;

    int target = 10;
    bool findInVec = vec3.find(target);

    /* print out the message if target is found or not. */
    if (findInVec)
        cout << "Target " << target << " can be found in vec1 or vec2" << endl;
    else
        cout << "Target " << target << " cannot be found in vec1 or vec2" << endl;

    Vec vec4;
    vec4 = vec3.independentSet();
    cout << "vec4: ";
    vec4.printVec();
    //delete [] array1;
    //delete [] array2;
    return 0;
}
