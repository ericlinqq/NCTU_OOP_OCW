// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

/* Write class definition for Matrix and add constructor and destructot*/
class Matrix
{
private:
   int dim;
   int** element;

public:
   Matrix();
   Matrix(int);
   Matrix(Matrix&);
   ~Matrix();

   void assignDimension(int);
   void assignElements();
   void printMatrix();
   void assignMatrix(Matrix&);
   void transposeMatrix();

   Matrix addMatrix(Matrix&);
   Matrix subtractMatrix(Matrix&);
   Matrix multiplyMatrix(Matrix&);
   void multiplyMatrix(Matrix&, Matrix&);
};

#endif