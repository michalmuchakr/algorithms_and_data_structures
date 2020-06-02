#include <iostream>
using namespace std;

struct node {
    int val;
    node *left;
    node *right;
};

node *createTree(int rootVal) {
    node *tree = new node();
    tree->val = rootVal;
    tree->left = NULL;
    tree->right = NULL;
}

node *searchForNode(node *root, int toFind) {
    if (root == NULL) {
        return NULL;
    }

    if (root->val == toFind) {
        return root;
    }

    if (toFind > root->val) {
        searchForNode(root->right, toFind);
    } else {
        searchForNode(root->left, toFind);
    }
}

void addBstNode(node *&root, int toAdd) {
    if (root == NULL) {
        node *tmp = new node;
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->val = toAdd;
        root = tmp;
        return;
    }

    if (toAdd >= root->val) {
        addBstNode(root->right, toAdd);
    } else {
        addBstNode(root->left, toAdd);
    }
}

void showInOrder(node *root) {
    if (root != NULL) {
        showInOrder(root->left);
        cout << root->val << " ";
        showInOrder(root->right);
    }
}

void showPreOrder(node *root) {
    if (root == NULL) {
        return;
    }

    cout << root->val << " ";
    showInOrder(root->left);
    showInOrder(root->right);
}

void showPostOrder(node *root) {
    if (root == NULL) {
        return;
    }

    showInOrder(root->left);
    showInOrder(root->right);
    cout << root->val << " ";
}

void deleteLevies(node *&root) {
    if (root->left == NULL && root->right == NULL) {
        delete root;
        root = NULL;
        return;
    }

    if (root->left != NULL) {
        deleteLevies(root->left);
    }

    if (root->right != NULL) {
        deleteLevies(root->right);
    }
}

void findMaxNode(node *root, node *& max) {
    if (root == NULL) {
        return;
    }


    if (root->right != NULL) {
        findMaxNode(root->right, max);
    } else {
        max = root;
    }
}

void findMinNode(node *root, node *& min) {
    if (root == NULL) {
        return;
    }

    if (root->left != NULL) {
        findMinNode(root->left, min);
    } else {
        min = root;
    }
}

int main() {
    node *tree = NULL;

    addBstNode(tree, 12);
    addBstNode(tree, 6);
    addBstNode(tree, 25);
    addBstNode(tree, 14);
    addBstNode(tree, 3);
    addBstNode(tree, 8);
    addBstNode(tree, 22);
    addBstNode(tree, 16);
    addBstNode(tree, 10);
    addBstNode(tree, 27);

    node *min = NULL;
    findMinNode(tree, min);
    return 0;
}
