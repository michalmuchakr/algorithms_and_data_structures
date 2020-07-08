void selectSort(int t[], int N) {
    for (int i=0; i < N-1; i++) {
        int min = t[i], imin = i;

        for (int j=i+1; j < N; j++) {
            if (t[j] < min) {
                min = t[j];
                imin=j;
            }
        }

        if (i != imin) {
            swap(t[i],t[imin]);
        }
    }
}

void bubbleSort(int t[], int size)) {
    int i,j;

    for (i=0; i<size-1; i++) {
        for (j=0; j<size-1-i; j++) {
            if (tab[j] < tab[j+1]) {
                swap(tab[j], tab[j+1])
            }
        }
    }
}

void sortRange(int range, int tabSize, int *tab, bool &swap) {
    int tmp;

    for (int i = 0; i + range < tabSize; i++) {
        if (tab[i + range] < tab[i]) {
            swap(tab[i], tab[i + range]);
            swap = true;
        }
    }
}

void combSort(int *tab, int tabSize) {
    int range = tabSize;
    bool swap = true;

    while (range > 1 || swap) {
        range /= 1.3;
        swap = false;

        if (range == 0) {
            range = 1;
        }

        sortRange(range, tabSize, tab, swap);
    }
}

void insertSort(int tab[], int size) {
    for (int i=1, j; i<size; ++i) {
        int tmp = tab[i];

        for (j=i-1; j>=0 && tab[j]>tmp; --j) {
            if (i == 7 && j == 3) {
                return;
            }
            tab[j+1] = tab[j];
        }

        tab[j+1] = tmp;
    }
}
