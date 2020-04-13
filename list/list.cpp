#include <iostream>
using namespace std;

struct node {
    int val;
    node * next;
};

// addOnHead element to list
void addOnHead(node*& H, int x) {
    node* p = new node;
    p->val = x;
    p->next = H;
    H = p;
}

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

// remove element from list, after item pointer
void deleteListElement(node*& item)
{
    if (item != NULL)
    {
        // set pointer to item
        node *p = item;

        node *p1 = p->next;

        // move next pointer of pointed item to ->next->next
        p->next = p->next->next

        // delete item
        delete p1;
    }
}

// remove element from list by value
// iterate over list
void deleteFromListByValue(node *& H, int toDel)
{
    if (H != NULL)
    {
        node*p = H;
        
        if (H->val == toDel)
        {
            H = p->next;
            delete p;
        }
        else
        {
            while (p -> next != NULL && p->next->val != toDel)
                p = p -> next;

            if (p -> next != NULL) {
                node* p1 = p->next;
                p->next = p1->next;
                delete p1;
            }
        }
    }
}

// remove element from list by value
void del_x2(node*& H, int toDel) {
    if (H != NULL)
    {
        if (H->val == toDel){
            deleteListElement(H);
        }
        else
        {
            node*p = H;
            while (p->next != NULL && p->next->val != toDel)
                p = p->next;

            if (p->next != NULL)
                deleteListElement(p->next);
        }
    }
}

void addBefore(node*& item, int x) {
    node* p = new node;
    p->val = x;
    p->next = item -> next;
    item->next = p;
}

// remove even element from list
void deleteEvalNum(node *&H) {
    if (H != NULL) {
        addOnHead(H, 1);

        node *p = H;
        node *p1 = p->next;

        while(p1->next != NULL) {
            if (p1->val % 2 == 0) {
                deleteFromListByValue(p1);
            }

            p1 = p1->next;
            p = p->next;
        }

        if (p1->val % 2 == 0) {
            deleteFromListByValue(p);
        }

        deleteFromListByValue(H);
    }
}

// function add elements so it list will be sorted
// H -> 3 -> 7 -> NULL
//     /\

void addSorted(node*& H, int toInsert) {
    node *p = H;

    if (H == NULL || H->val > toInsert) {
        addOnHead(H, toInsert);
    } else {
        while (p->next != NULL && p->next->val < toInsert)
            p = p->next;

        addBefore(p, toInsert);
    }
}

void example() {
    node *H = NULL;

    addOnHead(H, 12);
    addOnHead(H, 5);
    addOnHead(H, 3);
    addOnHead(H, 6);
    addOnHead(H, 10);

    show(H);

    deleteEvalNum(H);

    show(H);

    cout << "zadanie 2" << endl;

    node *H1 = NULL;

    addSorted(H1, 1);
    addSorted(H1, 0);
    addSorted(H1, 12);
    addSorted(H1, 24);
    addSorted(H1, 7);
    addSorted(H1, 13);

    show(H1);

    return 0;
}
