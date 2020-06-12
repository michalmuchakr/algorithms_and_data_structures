#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
//    ifstream file("/home/michal/Work/studies/4_term/AISD/laboratory/graph.txt");
//    string line;
    int size;
//
//    while (getline(file, line)) {
//        cout << line << endl;
//    }

    cout << "===========================" << endl;

    fstream read;
    read.open("graph.txt");
    read >> size;

    int **M = new int *[size];

    for (int i = 0; i < size; i++) {
        M[i] = new int[size];
    }

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            read >> M[i][j];


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Implementacja Algorytmu Kruskala,
// Odczytanie listy sąsiedztwa z pliku tekstowego(implementacja wskaźnikowa) - (w pliku mamy macierz sąsiedztwa);
// Utworzenie listy jednostronnie wiązanej posortowanych krawędzi,
// Realizacja algorytmu opartego o tablicy kolorów oraz lasów.
