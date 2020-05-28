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

void show(node *H) {
    node* p = H;
    cout << "Head->";
    while (p != NULL)
    {
        cout << p->val << "->";
        p = p->next;
    }
    cout << "NULL" << endl;
}

node *createListFromArray(int *tab, int tabLength) {
    node *H = NULL;

    for (int i = tabLength - 1; i >= 0; i--) {
        addOnHead(H, tab[i]);
    }

    return H;
}

int getSizeOfList(node *H) {
    int size = 0;
    node *p = H;

    while (p != NULL) {
        size = size + 1;
        p = p->next;
    }

    return size;
}

void splitLists(node *&H, node *&H1, node *&H2) {
    int sizeOfFirstList = getSizeOfList(H) / 2;
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
