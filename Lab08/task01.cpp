#include <iostream>
#include <string>
using namespace std;

struct Node {
    string packageName;
    Node* left;
    Node* right;
    Node(string name) {
        packageName = name;
        left = right = NULL;
    }
};

class TourTree {
public:
    Node* root;
    TourTree() { root = NULL; }

    Node* insert(Node* root, string name) {
        if (!root) return new Node(name);
        char choice;
        cout << "Insert " << name << " to left or right of " << root->packageName << "? (l/r): ";
        cin >> choice;
        if (choice == 'l') root->left = insert(root->left, name);
        else root->right = insert(root->right, name);
        return root;
    }

    void display(Node* root, int space = 0) {
        if (!root) return;
        space += 5;
        display(root->right, space);
        cout << endl;
        for (int i = 5; i < space; i++) cout << " ";
        cout << root->packageName << "\n";
        display(root->left, space);
    }
};

int main() {
    TourTree tree;
    int n;
    cout << "Enter number of tour packages: ";
    cin >> n;
    string name;
    for (int i = 0; i < n; i++) {
        cout << "Enter package name: ";
        cin >> name;
        if (!tree.root) tree.root = new Node(name);
        else tree.insert(tree.root, name);
    }
    cout << "\nTour Package Hierarchy:\n";
    tree.display(tree.root);
    return 0;
}
