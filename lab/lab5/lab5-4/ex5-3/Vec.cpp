// Vec.cpp
#include <iostream>
using std::cout;
using std::endl;

#include "Vec.h"

void swap(int&, int&);
int Partition(int*, int, int);
void QuickSort(int*, int, int);
int Select(int*, int, int, int);
int BinSearch(int*, int, int, int);

Vec::Vec() {
    array = NULL;
    dim = 0;
}

Vec::Vec(int *ar, int d) {
    array = ar;
    dim = d;
}

Vec::Vec(const Vec& v) {
    dim = v.dim;
    array = new int[dim];
    for (int i = 0; i < dim; i++)
        array[i] = v.array[i];
}

Vec::Vec(Vec&& v) {
    if (array != nullptr)
        delete [] array;
    array = v.array;
    dim = v.dim;
    v.array = nullptr;
    v.dim = 0;
}

Vec::~Vec() {
    delete [] array;
    array = NULL;
}

Vec& Vec::operator=(const Vec& v) {
    int* nA = new int[v.dim];
    for (int i = 0; i < v.dim; i++)
        nA[i] = v.array[i];
    delete [] array;
    array = nA;

    return *this;
}

Vec& Vec::operator=(Vec&& v) {
    if (array != nullptr)
        delete [] array;
    array = v.array;
    dim = v.dim;
    v.array = nullptr;
    v.dim = 0;
    return *this;
}

void Vec::assign(int *ar,  int d) {
    dim = d;
    array = new int[dim];
    for (int i = 0; i < dim; i++) {
        array[i] = ar[i];
    }
}

void Vec::sort() {
    QuickSort(array, 0, dim-1);
}

void Vec::printVec() {
    for (int i = 0; i < dim; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

bool Vec::isEqual(Vec &v) {
    int i = 0;
    while(1) {
        if (array[i] != v.array[i])
            return 0;
        i++;
        if (i == dim)
            return 1;
    }
}

void Vec::unionSet(Vec &v1, Vec &v2) {
    dim = v1.dim + v2.dim;
    array = new int[dim]{0};
    for (int i = 0; i < dim; i++) {
        if (i < v1.dim)
            array[i] = v1.array[i];
        else
            array[i] = v2.array[i-v1.dim];
    }
}

int Vec::min() {
    return Select(array, 0, dim-1, 1);
}

int Vec::max() {
    return Select(array, 0, dim-1, dim);
}

bool Vec::find(int target) {
    int idx = BinSearch(array, 0, dim-1, target);
    if (idx == -1)
        return 0;
    return 1;
}

Vec Vec::independentSet() {
    int *nA = new int[dim];
    int nA_dim = 0;
    for (int i = 0; i < dim; i++) {
        if (i == 0) {
            nA[nA_dim] = array[i];
            nA_dim++; 
        }
        else {
            if (BinSearch(nA, 0, nA_dim-1, array[i]) == -1) {
                nA[nA_dim] = array[i];
                nA_dim++;
            } 
        }
    }

    int *tmp = new int[nA_dim];
    for (int i = 0; i < nA_dim; i++) {
        tmp[i] = nA[i];
    }

    delete [] nA;
    nA = NULL;
    
    return Vec(tmp, nA_dim);
}
