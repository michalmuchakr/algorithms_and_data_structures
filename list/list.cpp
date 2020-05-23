#include <iostream>

using namespace std;

/****************************
 *          BASE            *
 ****************************/
struct node {
    int val;
    node * next;
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

/****************************
 *           ADD            *
 ****************************/

void addOnHead(node*& H, int x) {
    node* p = new node;
    p->val = x;
    p->next = H;
    H = p;
}

void addValueBeforePointer(node*& pointerBefore, int x) {
    node* p = new node;
    p->val = x;
    p->next = pointerBefore->next;
    pointerBefore->next = p;
}

void addAfterItemPtr(node*& item, int x) {
    node* p = new node;
    p->next = item->next;
    p->val = x;
    item->next = p;
}

/****************************
 *          DELETE          *
 ****************************/

void deleteOnHead(node *&H) {
    if (H != NULL) {
        node *p = H;
        H = p->next;
        delete p;
    }
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
    if (H == NULL) {
        return;
    }

    node*p = H;

    if (H->val == toDel)
    {
        H = p->next;
        delete p;
        return;
    }

    while (p -> next != NULL && p->next->val != toDel) {
        p = p -> next;
    }

    if (p -> next != NULL) {
        node* p1 = p->next;
        p->next = p1->next;
        delete p1;
    }
}

void deleteByVal(node *&H, int toCheck) {
    if (H == NULL) {
        return;
    }

    addOnHead(H, 1);

    node *p = H;
    while (p->next->val != toCheck && p->next != NULL)
        p = p->next;

    if (p->next->val == toCheck) {
        deleteItemAfterPtr(p);
    }

    deleteOnHead(H);
}

void deleteItemsBetween(node *&H, int x, int y) {
    if (H == NULL || H->next == NULL || H->next->next == NULL) {
        return;
    }

    // add guard
    addOnHead(H, 1);

    node *p = H;
    // search for x
    while (p->next != NULL && p->next->val != x) {
        p = p->next;
    }

    if (p->next->val != x) {
        return;
    }

    node *X = p->next;

    // search for y
    while (p->next->val != y && p->next != NULL) {
        p = p->next;
    }

    if (p->next->val != y) {
        return;
    }

    node *Y = p->next;

    while (X->next != Y) {
        deleteItemAfterPtr(X);
    }

    //remove guard
    deleteOnHead(H);
}

/****************************
 *       MOVE & REPLACE     *
 ****************************/
void replaceFirstWithLast(node *&H) {
    if (H == NULL || H->next == NULL) {
        return;
    }

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

void moveItemsInPairs(node *&ptrBeforePair) {
    node *x1 = ptrBeforePair->next;
    ptrBeforePair->next = ptrBeforePair->next->next;
    x1->next = ptrBeforePair->next->next;
    ptrBeforePair->next->next = x1;
}

void replaceItemsAfterPointers(node *&ptrBeforeOne, node *&ptrBeforeTwo) {
    if (ptrBeforeOne->next != ptrBeforeTwo) {
        node *tmp1 =  ptrBeforeOne->next;
        node *tmp2 =  ptrBeforeTwo->next;
        node *tmp3 =  ptrBeforeTwo->next->next;

        ptrBeforeTwo->next->next = ptrBeforeOne->next->next;
        ptrBeforeTwo->next = ptrBeforeOne->next;
        ptrBeforeTwo->next->next = tmp3;
        ptrBeforeOne->next = tmp2;

        return;
    }

    moveItemsInPairs(ptrBeforeOne);
}

void moveMaxToHead(node *&H) {
    if (H == NULL || H->next == NULL) {
        return;
    }

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

    if (before_max->next->val > H->val) {
        node* max = before_max->next;

        before_max->next = before_max->next->next;
        max->next = H;
        H = max;
    }
}

void moveItemAfterPtrToHeadOfDestinyList(node *&ptrBefore, node *&destinyList) {
    if (ptrBefore == NULL || ptrBefore->next == NULL) {
        return;
    }

    if (destinyList == NULL) {
        destinyList = ptrBefore->next;
        ptrBefore->next = ptrBefore->next->next;
        destinyList->next = NULL;
    } else {
        node *ptr = ptrBefore->next;
        ptrBefore->next = ptrBefore->next->next;
        node *ptr2 = destinyList;
        destinyList = ptr;
        destinyList->next = ptr2;
    }
}

void moveItemAfterTail(node *ptrBefore, node *tail) {
    if (ptrBefore->next == tail) {
        moveItemsInPairs(ptrBefore);
        return;
    }

    node *x =  ptrBefore->next;

    ptrBefore->next = x->next;
    x->next = tail->next;
    tail->next = x;
}

void changeNextTwoItemOrder(node *&ptrBefore) {
    node *x1 = ptrBefore->next;
    node *x2 = x1->next;
    x1->next = x2->next;
    ptrBefore->next = x2;
    x2->next = x1;
};

void changeTwoItemsOrder(node *&ptrBefore1, node *&ptrBefore2) {
    node *x1 = ptrBefore1->next;

    ptrBefore1->next = ptrBefore2->next;
    ptrBefore2->next = x1;

    node *tmp = x1->next;
    x1->next = ptrBefore1->next->next;
    ptrBefore1->next->next = tmp;
}

void moveGraterThanAverageAfterTail(node *&H) {
    node* p = H;
    int amountOfElements = 0;
    double sum = 0;

    while (p->next != NULL) {
        amountOfElements++;
        sum += p->val;
        p = p->next;
    }

    // add last item
    amountOfElements++;
    sum += p->val;

    double average = sum / amountOfElements;

    node *currentTail = p;
    node *baseTail = p;

    // add guard
    addOnHead(H, 0);
    p = H;

    // Head->4->4->2->6->NULL
    //            |p| |
    while (p->next != baseTail) {
        if (p->next->val > average) {
            moveItemAfterTail(p, currentTail);
            currentTail = currentTail->next;
        }
        p = p->next;
    }

    // check if baseTail should be moved after currentTail
    if (p->next->val > average) {
        moveItemAfterTail(p, currentTail);
        currentTail = currentTail->next;
    }

    // remove guard
    deleteOnHead(H);
}

/****************************
 *           FIND           *
 ****************************/
node *findTailOnList(node *&H) {
    if (H == NULL || H->next == NULL) {
        return H;
    }

    node *p = H;

    while (p->next != NULL) {
        p = p->next;
    }

    return p;
};

/****************************
 *  VARIATIONS & EXERCISES  *
 ****************************/
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

    //remove guard
    deleteOnHead(H);
}

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

bool isFibonacciMember(int toCheck) {
    if (toCheck == 1 || toCheck == 0) {
        return true;
    }

    int x = 0;
    int y = 1;
    int z = 1;

    while (z <=  toCheck) {
        if (z == toCheck) {
            return true;
        }
        x = y;
        y = z;
        z = x + y;
    }

    return false;
}

node* joinLists(node *& listOne, node *& listTwo) {
    node *tail = findTailOnList(listOne);
    tail->next = listTwo;
    return listOne;
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