#include <iostream>
using namespace std;

struct node {
    node* next;
    int val;
};

void top(node *Q) {
    if (Q == NULL) {
        cout << "List is empty" << endl;
    }
    else {
        cout << Q->val << endl;
    }
}

void addToQueue(node *&Q, node *&T, int x) {
    node *p = new node;
    p->next = NULL;
    p->val = x;

    if (Q == NULL) {
        Q=T=p;
    }
    else {
        T->next = p;
        T = T->next;
    }
}

void remove(node *&Q) {
    if (Q != NULL) {
        node *p = Q;
        Q = Q->next;
        delete p;
    }
}

void example() {
    node* Q = NULL;
    node* T = NULL;

    addToQueue(Q, T, 1);
    addToQueue(Q, T, 12);
    addToQueue(Q, T, 12);
    addToQueue(Q, T, 10);

    top(Q);
}
