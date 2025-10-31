#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;
    Node* nodes[100];
    int count;
    BinaryTree() {
        root = NULL;
        count = 0;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        nodes[count] = newNode;
        if (count == 0) root = newNode;
        else {
            int parent = (count - 1) / 2;
            if (count % 2 == 1) nodes[parent]->left = newNode;
            else nodes[parent]->right = newNode;
        }
        count++;
    }

    int subtreeSum(Node* root, int target, bool &found, Node* &match) {
        if (!root) return 0;
        int sum = root->data + subtreeSum(root->left, target, found, match) + subtreeSum(root->right, target, found, match);
        if (sum == target && !found) {
            found = true;
            match = root;
        }
        return sum;
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

    bool findSubtreeWithSum(int target) {
        bool found = false;
        Node* match = NULL;
        subtreeSum(root, target, found, match);
        if (found) {
            cout << "\nSubtree with sum " << target << ":\n";
            display(match);
            return true;
        }
        return false;
    }
};

int main() {
    BinaryTree tree;
    int n, val, target;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        tree.insert(val);
    }

    cout << "\nEnter target sum: ";
    cin >> target;

    cout << "\nComplete Binary Tree:\n";
    tree.display(tree.root);

    if (!tree.findSubtreeWithSum(target))
        cout << "\nNo subtree found with sum " << target << ".\n";
    
    return 0;
}
