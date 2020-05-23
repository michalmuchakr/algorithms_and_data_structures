//
// Created by michal on 17.05.2020.
//

#include <iostream>
using namespace std;

struct node {
    int val;
    node * next;
};

// display list
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

// addOnHead element to list
void addOnHead(node*& H, int x) {
    node* p = new node;
    p->val = x;
    p->next = H;
    H = p;
}

node *createListFromArray(int *tab, int tabLength) {
    node *H = NULL;

    for (int i = tabLength - 1; i >= 0; i--) {
        addOnHead(H, tab[i]);
    }

    return H;
}

int main() {
    int tab[5] = {0, 8, 1, 1, 2};
    node *H = createListFromArray(tab, 5);

    show(H);



    show(H);

    return 0;
}
