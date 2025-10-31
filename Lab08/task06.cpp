#include <iostream>
using namespace std;

struct Node {
    int empID;
    Node* left;
    Node* right;
    Node(int id) {
        empID = id;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;
    BST() { root = NULL; }

    Node* insert(Node* root, int id) {
        if (!root) return new Node(id);
        if (id < root->empID)
            root->left = insert(root->left, id);
        else if (id > root->empID)
            root->right = insert(root->right, id);
        return root;
    }

    Node* findLCA(Node* root, int id1, int id2) {
        if (!root) return NULL;
        if (root->empID > id1 && root->empID > id2)
            return findLCA(root->left, id1, id2);
        if (root->empID < id1 && root->empID < id2)
            return findLCA(root->right, id1, id2);
        return root;
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->empID << " ";
        inorder(root->right);
    }
};

int main() {
    BST tree;
    int n, id;
    cout << "Enter number of employees: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter Employee ID: ";
        cin >> id;
        tree.root = tree.insert(tree.root, id);
    }

    cout << "\nEmployee Hierarchy (Inorder Traversal): ";
    tree.inorder(tree.root);
    cout << endl;

    int id1, id2;
    cout << "Enter first employee ID: ";
    cin >> id1;
    cout << "Enter second employee ID: ";
    cin >> id2;

    Node* lca = tree.findLCA(tree.root, id1, id2);
    if (lca)
        cout << "\nClosest Common Manager (LCA) of " << id1 << " and " << id2 << " is Employee ID: " << lca->empID << endl;
    else
        cout << "\nOne or both employee IDs not found in the tree.\n";

    return 0;
}
