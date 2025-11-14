#include <iostream>
using namespace std;

class Node {
public:
    int rollNumber;
    Node* left;
    Node* right;
    int height;
    Node(int roll) : rollNumber(roll), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;

    int height(Node* node) {
        return (node == nullptr) ? 0 : node->height;
    }

    int balanceFactor(Node* node) {
        return (node == nullptr) ? 0 : height(node->left) - height(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    Node* insert(Node* node, int rollNumber) {
        if (node == nullptr)
            return new Node(rollNumber);

        if (rollNumber < node->rollNumber)
            node->left = insert(node->left, rollNumber);
        else if (rollNumber > node->rollNumber)
            node->right = insert(node->right, rollNumber);

        node->height = max(height(node->left), height(node->right)) + 1;

        int balance = balanceFactor(node);

        if (balance > 1 && rollNumber < node->left->rollNumber)
            return rightRotate(node);

        if (balance < -1 && rollNumber > node->right->rollNumber)
            return leftRotate(node);

        if (balance > 1 && rollNumber > node->left->rollNumber) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && rollNumber < node->right->rollNumber) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int rollNumber) {
        root = insert(root, rollNumber);
    }

    void preOrder(Node* node) {
        if (node == nullptr)
            return;
        cout << node->rollNumber << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void display() {
        preOrder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(15);

    tree.display();

    return 0;
}

