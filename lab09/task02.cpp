#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;
    int height;
    Node(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
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

    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->value)
            node->left = insert(node->left, value);
        else if (value > node->value)
            node->right = insert(node->right, value);

        node->height = max(height(node->left), height(node->right)) + 1;

        int balance = balanceFactor(node);

        if (balance > 1 && value < node->left->value)
            return rightRotate(node);

        if (balance < -1 && value > node->right->value)
            return leftRotate(node);

        if (balance > 1 && value > node->left->value) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && value < node->right->value) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void preOrder(Node* node) {
        if (node == nullptr)
            return;
        cout << node->value << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void leftRotateRoot() {
        if (root != nullptr) {
            root = leftRotate(root);
        }
    }

    void display() {
        preOrder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Tree before insertion and rotation: ";
    tree.display();

    tree.insert(55); 

    cout << "Tree after inserting 55: ";
    tree.display();

    tree.leftRotateRoot(); 

    cout << "Tree after left rotation on the root: ";
    tree.display();

    return 0;
}
