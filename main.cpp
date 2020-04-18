#include <iostream>
using namespace std;

struct node {
    int val;
    node * next;
};

//void switchElementsAfterPtr(node *&ptr) {
//    node *p1 = ptr->next;
//    node *p2 = p1->next;
//
//    ptr->next = p1->next;
//    p1->next = p2->next;
//    p2->next = p1;
//}
//
//void switcher(node *H) {
//    addOnHead(H, -1);
//    node *p = H;
//
//    while (p != NULL || p->next != NULL) {
//        if ((p->val + p->next->val) % 2) {
//
//        }
//        switchElementsAfterPtr(p);
//        p = p->next->next;
//    }
//
//    deleteOnTail(H);
//}

int main() {
    return 0;
}
