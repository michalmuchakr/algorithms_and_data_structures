#include <iostream>
using namespace std;

struct node {
    node *next;
    int length;
    int val;
};

void deleteItemAfterPtr(node*& item)
{
    if (item == NULL) {
        return;
    }

    node *p = item;
    node *p1 = p->next;
    p->next = p->next->next;
    delete p1;
}

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

void removeGraterThanProvided(node **&nbrList, int size, int x) {
    if (nbrList == NULL) {
        return;
    }

    node *ptr;
    for(int i = 0; i<size; i++) {
        if (ptr == NULL) {
            continue;
        }

        p = nbrList[i];

        // guard
        addOnHead(p, 0);

        while (ptr -> next != NULL) {
            if (ptr->next->length > x) {
                deleteItemAfterPtr(ptr);
            }
            ptr = ptr->next;
        }

        // remove guard
        deleteOnHead(nbrList[i]);
    }
}

int main() {

    return 0;
}
