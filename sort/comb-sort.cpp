#include <iostream>
using namespace std;

struct node {
    node* next;
    int val;
};

void addOnHead(node*& H, int x) {
    node* p = new node;
    p->val = x;
    p->next = H;
    H = p;
}

void deleteOnHead(node *&H) {
    if (H != NULL) {
        node *p = H;
        H = p->next;
        delete p;
    }
};

int getSizeOfList(node *H) {
    int size = 0;
    node *p = H;

    while (p != NULL) {
        size = size + 1;
        p = p->next;
    }

    return size;
}

// H -> x1 -> x2 -> x3 -> x4 -> x5 -> NULL;
void splitLists(node *&H, node *&H1, node *&H2) {
    int sizeOfFirstList = getSizeOfList(H) / 2; // 2
    node *p = H;

    for (int i = 0; i < sizeOfFirstList - 1; i++) {
        p = p->next;
    }

    H1 = H;
    H2 = p->next;
    p->next = NULL;
    H = NULL;
}

void joinArrays(node *&H, node *&H1, node *&H2) {
    // add guard
    addOnHead(H, 1);

    node *tail = H;

    while (H1 && H2) {
        if (H1->val < H2->val) {
            tail->next = H1;
            H1 = H1->next;
        } else {
            tail->next = H2;
            H2 = H2->next;
        }

        tail = tail->next;
    }

    if (H1 == NULL) {
        tail->next = H2;
        H2 = NULL;
    } else {
        tail->next = H1;
        H1 = NULL;
    }

    delete H1;
    delete H2;

    //remove guard
    deleteOnHead(H);
}

void mergeSort(node *&H) {
    if (H == NULL || H->next == NULL) {
        return;
    }

    node *H1 = NULL;
    node *H2 = NULL;

    splitLists(H, H1, H2);

    mergeSort(H1);
    mergeSort(H2);

    joinArrays(H, H1, H2);
}

void showTab(int *tab, int size) {
    cout << "[";

    for (int i = 0; i < size; i++) {
        cout << *(tab + i);

        if (i != size-1) {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

void sortRange(int range, int tabSize, int *tab, bool &swap) {
    int tmp;

    for (int i = 0; i + range < tabSize; i++) {
        if (tab[i + range] < tab[i]) {
            tmp = tab[i];
            tab[i] = tab[i + range];
            tab[i + range] = tmp;
            swap = true;
        }
    }
}

void combSort(int *tab, int tabSize) {
    int range = tabSize;
    bool swap = true;

    while (range > 1 || swap) {
        range /= 1.3;

        if (range == 0) {
            range = 1;
        }

        swap = false;

        sortRange(range, tabSize, tab, swap);
    }
}

int main() {
    int tab[5] = {2,3,1,4,7};

    showTab(tab, 5);
    combSort(tab, 5);
    showTab(tab, 5);

    return 0;
}
