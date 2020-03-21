#include <iostream>
#include "matrix.h"

using namespace std;

int ** Matrix::allocateMatrix()
{
    int **Matrix = new int*[sizeX];
    
    for (int i=0; i<sizeX; i++)
    {
        Matrix[i] = new int[sizeY];
    }
    
    return Matrix;
}

void Matrix::nullMatrix()
{
    for (int i=0; i<sizeX; i++)
    {
        for (int j=0; j<sizeY; j++)
        {
            baseMatrix[i][j] = 0;
        }
    }
}

void Matrix::displayMatrix()
{
    for (int i=0; i<sizeX; i++)
    {
        for (int j=0; j<sizeY; j++)
        {
            cout << baseMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix::Matrix(int x, int y): sizeX(x), sizeY(y)
{
}
