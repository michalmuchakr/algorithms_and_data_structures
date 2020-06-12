void moveItemsInPairs(node *&ptrBeforePair) {
    node *x1 = ptrBeforePair->next;
    ptrBeforePair->next = ptrBeforePair->next->next;
    x1->next = ptrBeforePair->next->next;
    ptrBeforePair->next->next = x1;
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

void addOnHead(node*& H, int x) {
    node* p = new node;
    p->val = x;
    p->next = H;
    H = p;
}

void bubbleSort(node *H) {
    if (H == NULL || H->next == NULL) {
        return;
    }

    int size = getSizeOfList(H);

    // guard
    addOnHead(H, 0);

    for (int i=0; i<size-1; i++) {
        node *p = H;
        while (p->next != NULL && p->next->next != NULL) {
            if (p->next->val > p->next->next->val) {
                moveItemsInPairs(p);
            }
            p = p->next;
        }
    }

    // guard
    deleteOnHead(H);
}