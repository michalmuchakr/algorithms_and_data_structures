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
    while (p != NULL) {
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
