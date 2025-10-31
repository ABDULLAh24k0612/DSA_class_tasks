#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;
    Node(string d) {
        data = d;
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

    int countNodes(Node* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int countLeafNodes(Node* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        return countLeafNodes(root->left) + countLeafNodes(root->right);
    }

    int height(Node* root) {
        if (!root) return 0;
        int leftH = height(root->left);
        int rightH = height(root->right);
        return 1 + (leftH > rightH ? leftH : rightH);
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
        cout << "Enter data: ";
        cin >> val;
        if (!tree.root) tree.root = new Node(val);
        else tree.root = tree.insert(tree.root, val);
    }

    cout << "\nTree Structure:\n";
    tree.display(tree.root);
    cout << "\nTotal Nodes: " << tree.countNodes(tree.root);
    cout << "\nLeaf Nodes: " << tree.countLeafNodes(tree.root);
    cout << "\nHeight of Tree: " << tree.height(tree.root);
    cout << endl;
    return 0;
}
