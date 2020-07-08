#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int **createArrFromFile2D (string fileName, int &size) {
    fstream read;

    read.open(fileName);
    read >> size;

    int **M = new int *[size];

    for (int i = 0; i < size; i++) {
        M[i] = new int[size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            read >> M[i][j];
        }
    }
}

void displayTab2d(int **tab, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int size;
    int **siblingsArr = createArrFromFile2D("/home/michal/Work/studies/4_term/AISD/laboratory/graph.txt", size);

    displayTab2d(siblingsArr, size);

    return 0;
}
