//
// Created by michal on 17.05.2020.
//

node * getNodeFromStack(node *&H) {
    if (H != NULL) {
        node *p = H;
        H = H->next;
        return p;
    }
}