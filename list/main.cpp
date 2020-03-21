#include <iostream>
using namespace std;

struct node {
    int val;
    node * next;
};

// dodaje element na początek
// parametr jako referencja wskaznikowa -> zmiana parametru
void add(node*& H, int x) {
    node* p = new node;
    p->val = x;
    p->next = H;
    H = p;
}

// wyświetla cala liste listę
// parametr jako referencja -> parametr do odczytu
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

// usuwa pierwszy element z listy
// parametr jako referencja wskaznikowa -> zmiana parametru
// będziemy modyfikować element, usuwamy go
void deleteListElement(node*& H)
{
    if (H != NULL)
    {
        // ustawia na poczatek listy
        node* p = H;
        
        // przesuwamy na nastepnika, pierwszy el. listy za headerem
        H = p->next;
        
        // usuwam obiekt
        delete p;
    }
}

// usuwa podany element z listy
// parametr jako referencja wskaznikowa -> zmiana parametru
// będziemy modyfikować element, usuwamy go
// petla przerywa gdy znajdzie element
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
            {
                p = p -> next;
                
                if (p -> next != NULL) {
                    node* p1 = p->next;
                    p->next = p1->next;
                    delete p1;
                }
            }
        }
    }
}

// usuwa podany element z listy
// parametr jako referencja wskaznikowa -> zmiana parametru
// będziemy modyfikować element, usuwamy go
// petla przerywa gdy znajdzie element
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

// STOS
// odklada element na górę stosu
void push() {
    
}

// STOS
// bierze element z góry stosu
void pop() {
    
}

// STOS
// sprawdza czy stos jest pusty
bool isEmpty(node *H) {
    if (H != NULL)
        return 0;
    else
        return 1;
}

// STOS
// sprawdza element na wierzchu stosu
void onTop() {
    
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
