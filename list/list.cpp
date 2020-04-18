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

void deleteOnHead(node *&H) {
    if (H != NULL) {
        node *p = H;
        H = p->next;
        delete p;
    }
};

// remove element from list, after item pointer
void deleteItemAfterPtr(node*& item)
{
    if (item != NULL)
    {
        // set pointer to item
        node *p = item;

        node *p1 = p->next;

        // move next pointer of pointed item to ->next->next
        p->next = p->next->next;

        // delete item
        delete p1;
    }
}

void deleteOnTail(node*& H)
{
    node *p = H;

    while (p->next->next != NULL) {
        p = p->next;
    }

    deleteItemAfterPtr(p);
}

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
            deleteItemAfterPtr(H);
        }
        else
        {
            node*p = H;
            while (p->next != NULL && p->next->val != toDel)
                p = p->next;

            if (p->next != NULL)
                deleteItemAfterPtr(p->next);
        }
    }
}

void addBefore(node*& item, int x) {
    node* p = new node;
    p->val = x;
    p->next = item -> next;
    item->next = p;
}

void deleteEvalNum(node *&H) {
    if (H != NULL) {
        addOnHead(H, 1);

        node *p = H;
        node *p1 = p->next;

        while(p1->next != NULL) {
            if (p1->val % 2 == 0) {
                deleteItemAfterPtr(p1);
            }

            p1 = p1->next;
            p = p->next;
        }

        if (p1->val % 2 == 0) {
            deleteItemAfterPtr(p);
        }

        deleteItemAfterPtr(H);
    }
}

void addInSortedWay(node*& H, int toInsert) {
    node *p = H;

    if (H == NULL || H->val > toInsert) {
        addOnHead(H, toInsert);
    } else {
        while (p->next != NULL && p->next->val < toInsert)
            p = p->next;

        addBefore(p, toInsert);
    }
}

void addAfterPtr(node*& item, int x) {
    node* p = new node;
    p->next = NULL;
    p->val = x;
    item->next = p;
}

void deleteFromListBetween(node *&H, int x, int y) {
    // check if more than two elements in list
    if (H == NULL || H->next != NULL || H->next->next == NULL) {
        return;
    }

    node *p = H;

    // check if found x, or if there p points to second node before NULL
    while (p->val != x && p->next->next != NULL)
        p = p->next;

    // x found
    if (p->val != x) {
        return;
    }

    node *q = p;

    // check if y exists
    while (q->val != y && q->next != NULL) {
        q = q->next;
    }

    // y found
    if (q->val == y) {
        while (p->next != q) {
            deleteItemAfterPtr(p);
        }
    }
}

void moveAfterTailFromListBetween(node *&H, int x, int y) {
    // check if more than two elements in list
    if (H == NULL || H->next == NULL || H->next->next == NULL) {
        return;
    }

    node *p = H;

    // check if found x, or if there p points to second node before NULL
    while (p->val != x && p->next->next != NULL) {
        p = p->next;
    }

    // x found
    if (p->val != x) {
        return;
    }

    node *q = p;

    // check if y exists
    while (q->val != y && q->next != NULL) {
        q = q->next;
    }

    // y found
    if (q->val != y) {
        return;
    }

    // will points to tail
    node *t = q;

    // find tail
    while (t->next != NULL) {
        t = t->next;
    }

    while (p->next != q) {
        t->next = p->next;
        t = t->next;
        p->next = p->next->next;
        t->next = NULL;
    }
}

void replaceFirstWithLast(node *&H) {
    if (H != NULL && H->next != NULL) {
        if (H->next->next == NULL) {
            node* tail = H->next;
            tail->next = H;
            H = tail;
            tail->next->next = NULL;
            return;
        }

        node *before_tail = H;

        while (before_tail->next->next != NULL) {
            before_tail = before_tail->next;
        }

        node *tail = before_tail->next;
        before_tail->next->next = H->next;
        before_tail->next = H;
        before_tail->next->next = NULL;
        H = tail;
    }
}


void moveMaxToHead(node *&H) {
    if (H == NULL || H->next == NULL) {
        return;
    }

    // add guard
//    addOnHead(H, -1);

    node *before_max = H;
    node *ptr = H;

    while (ptr->next->next != NULL) {
        if (before_max->next->val < ptr->next->val ) {
            before_max = ptr;
        }
        ptr = ptr->next;
    }

    // check last element
    if (before_max->next->val < ptr->next->val ) {
        before_max = ptr;
    }

    // remove guards
//    deleteOnHead(H);

    if (before_max->next->val > H->val) {
        node* max = before_max->next;

        before_max->next = before_max->next->next;
        max->next = H;
        H = max;
    }
}

// move max to Head
void sortList(node *&H) {
    if (H == NULL || H->next == NULL) {
        return;
    }

    // add guard
    addOnHead(H, -1);
    node *guard = H;

    while (guard->next != NULL) {
        node *before_max = guard;
        node *ptr = guard;

        while (ptr->next->next != NULL) {
            if (before_max->next->val < ptr->next->val ) {
                before_max = ptr;
            }
            ptr = ptr->next;
        }

        // check last element
        if (before_max->next->val < ptr->next->val ) {
            before_max = ptr;
        }

        node* max = before_max->next;

        before_max->next = before_max->next->next;
        max->next = H;
        H = max;
    }

    deleteOnTail(H);
}

node * getNodeFromStack(node *&H) {
    if (H != NULL) {
        node *p = H;
        H = H->next;
        return p;
    }
}

void addAfterItemPtr(node*& item, int x) {
    node* p = new node;
    p->next = NULL;
    p->val = x;
    item->next = p;
}

void deleteByValue(node *&H, int toDelete) {
    if (H != NULL) {
        if (H->val == toDelete) {
            deleteOnHead(H);
        } else {
            node *p = H;

            while (p->next->val != toDelete && p->next != NULL)
                p = p->next;

            if (p->next->val == toDelete) {
                deleteItemAfterPtr(p);
            }
        }
    }
};

void copyOnEndRevertedList(node *&H) {
    if (H == NULL || H->next == NULL) {
        return;
    }

    node *stack = NULL;
    node *ptr = H;

    while (ptr->next != NULL) {
        addOnHead(stack, ptr->val);
        ptr = ptr->next;
    }

    // copy last element
    addAfterItemPtr(ptr, ptr->val);

    // ptr will points to tail
    ptr = ptr->next;

    while (stack != NULL) {
        node *toInsert = getNodeFromStack(stack);
        ptr->next = toInsert;
        toInsert->next = NULL;
        ptr = ptr->next;
    }
}

node *createListFromArray(int *tab, int tabLength) {
    node *H = NULL;

    for (int i = tabLength - 1; i >= 0; i--) {
        addOnHead(H, tab[i]);
    }

    return H;
}


int main() {
    int tab[1] = {5};


    return 0;
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
