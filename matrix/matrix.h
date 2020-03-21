#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
    int ** baseMatrix;
public:
    int sizeX;
    int sizeY;
    int **allocateMatrix();
    void nullMatrix();
    void displayMatrix();
    Matrix(int x, int y);
};

#endif // MATRIX_H
