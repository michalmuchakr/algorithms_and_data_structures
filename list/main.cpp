#include <iostream>
using namespace std;

struct node {
    int val;
    node * next;
};

// add element to list
void add(node*& H, int x) {
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

// remove element from list
void deleteListElement(node*& H)
{
    if (H != NULL)
    {
        // set pointer to top of list
        node* p = H;

        // move header to next element
        H = p->next;

        // delete item
        delete p;
    }
}

// remove element from list by value
void del(node *& H, int toDel)
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

// KOLEJKA
// dodaj element do kolejki
void enqueue(node *&Q, node *&T, int x)
{
    node *p = new node;
    p->val=x;
    p->next=NULL;
    if(Q==NULL)
    {
        Q=T=p;
    }
    else
    {
        T->next=p;
        T=T->next;
    }
}

int main() {
    node* H = NULL;
    
    add(H, 17);
    add(H, 1);
    add(H, 12);

    del_x2(H, 12);
    show(H);

    // KOLEJKA
    node* Q=NULL;
    node* T=NULL;
    
    enqueue(Q,T,10);
    enqueue(Q,T,7);
    
    return 0;
}
