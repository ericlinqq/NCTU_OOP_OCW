// Matrix.cpp
#include <iostream>
using std::cout;
using std::endl;

#include "Matrix.h"


// Member-function definitions for class Matrix.
Matrix::Matrix() {
    dim = 0;
    element = NULL;
}

Matrix::Matrix(int n) {
    dim = n;
    element = new int*[dim];
    for (int i = 0; i < dim; i++) {
        element[i] = new int[dim];
    }
}

Matrix::Matrix(Matrix &M) {
    dim = M.dim;
    // deep copy
    element = new int*[dim];
    for (int i = 0; i < dim; i++) {
        element[i] = new int[dim];
        for (int j = 0; j < dim; j++) {
            element[i][j] = M.element[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < dim; i++) delete [] element[i]; 
    delete [] element;
    element = NULL;
}

void Matrix::assignDimension(int n) {
    dim = n;
    element = new int*[dim];
    for (int i = 0; i < dim; i++) {
        element[i] = new int[dim];
    }
}

void Matrix::assignElements() {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            element[i][j] = rand()%10+1;
        }
    }
}

void Matrix::printMatrix() {
    cout << endl;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            cout << element[i][j] << " ";
        }
        cout << endl;
    }
}

void Matrix::assignMatrix(Matrix &m) {
    dim = m.dim;
    element = new int*[dim];

    for (int i = 0; i < dim; i++) {
        element[i] = new int[dim];
        for (int j = 0; j < dim; j++) {
            element[i][j] = m.element[i][j];
        }
    }
}

void Matrix::transposeMatrix() {
    for (int i = 0; i < dim; i++) {
        for (int j = i+1; j < dim; j++) {
            int tmp = element[i][j];
            element[i][j] = element[j][i];
            element[j][i] = tmp;    
        }
    }
}

Matrix Matrix::addMatrix(Matrix &m) {
    Matrix tmp;
    tmp.assignDimension(dim);
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            tmp.element[i][j] = element[i][j] + m.element[i][j];
        }
    }

    return tmp;
}

Matrix Matrix::subtractMatrix(Matrix &m) {
    Matrix tmp;
    tmp.assignDimension(dim);
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            tmp.element[i][j] = element[i][j] - m.element[i][j];
        }
    }

    return tmp;
}

Matrix Matrix::multiplyMatrix(Matrix &m) {
    Matrix tmp;
    tmp.assignDimension(dim);
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            for (int k = 0; k < dim; k++) {
                tmp.element[i][j] += element[i][k] * m.element[k][j];
            }
        }
    }

    return tmp;
}

void Matrix::multiplyMatrix(Matrix &m1, Matrix &m2) {
    dim = m1.dim;
    element = new int*[dim];
    for (int i = 0; i < dim; i++) {
        element[i] = new int[dim];
        for (int j = 0; j < dim; j++) {
            for (int k = 0; k < dim; k++) {
                element[i][j] += m1.element[i][k] * m2.element[k][j];
            }
        }
    }
}