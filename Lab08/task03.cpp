#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;
    Node(string val) {
        data = val;
        left = right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() { root = NULL; }

    Node* insert(Node* root, string val) {
        if (!root) return new Node(val);
        char choice;
        cout << "Insert " << val << " to left or right of " << root->data << "? (l/r): ";
        cin >> choice;
        if (choice == 'l') root->left = insert(root->left, val);
        else root->right = insert(root->right, val);
        return root;
    }

    bool isFull(Node* root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;
        if (root->left && root->right)
            return isFull(root->left) && isFull(root->right);
        return false;
    }

    void display(Node* root, int space = 0) {
        if (!root) return;
        space += 5;
        display(root->right, space);
        cout << endl;
        for (int i = 5; i < space; i++) cout << " ";
        cout << root->data << "\n";
        display(root->left, space);
    }
};

int main() {
    BinaryTree tree;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    string val;
    for (int i = 0; i < n; i++) {
        cout << "Enter node data: ";
        cin >> val;
        if (!tree.root) tree.root = new Node(val);
        else tree.root = tree.insert(tree.root, val);
    }

    cout << "\nTree Structure:\n";
    tree.display(tree.root);

    if (tree.isFull(tree.root))
        cout << "\nThe tree is a full binary tree.\n";
    else
        cout << "\nThe tree is not a full binary tree.\n";

    return 0;
}
