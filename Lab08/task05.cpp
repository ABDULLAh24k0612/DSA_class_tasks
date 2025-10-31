#include <iostream>
using namespace std;

struct Node {
    int productID;
    int quantity;
    Node* left;
    Node* right;
    Node(int id, int qty) {
        productID = id;
        quantity = qty;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;
    BST() { root = NULL; }

    Node* insert(Node* root, int id, int qty) {
        if (!root) return new Node(id, qty);
        if (id < root->productID)
            root->left = insert(root->left, id, qty);
        else if (id > root->productID)
            root->right = insert(root->right, id, qty);
        else
            root->quantity = qty;
        return root;
    }

    Node* search(Node* root, int id) {
        if (!root || root->productID == id) return root;
        if (id < root->productID) return search(root->left, id);
        return search(root->right, id);
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << "Product ID: " << root->productID << " | Quantity: " << root->quantity << endl;
        inorder(root->right);
    }

    void findMaxQuantity(Node* root, Node* &maxNode) {
        if (!root) return;
        if (!maxNode || root->quantity > maxNode->quantity) maxNode = root;
        findMaxQuantity(root->left, maxNode);
        findMaxQuantity(root->right, maxNode);
    }
};

int main() {
    BST tree;
    int choice, id, qty;
    while (true) {
        cout << "\n1. Add/Update Product\n2. Search Product\n3. Display All Products\n4. Product with Highest Quantity\n5. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter Quantity: ";
            cin >> qty;
            tree.root = tree.insert(tree.root, id, qty);
            cout << "Product added/updated successfully.\n";
        } 
        else if (choice == 2) {
            cout << "Enter Product ID to search: ";
            cin >> id;
            Node* res = tree.search(tree.root, id);
            if (res) cout << "Product Found | Quantity: " << res->quantity << endl;
            else cout << "Product not found.\n";
        } 
        else if (choice == 3) {
            if (!tree.root) cout << "No products available.\n";
            else tree.inorder(tree.root);
        } 
        else if (choice == 4) {
            if (!tree.root) cout << "No products available.\n";
            else {
                Node* maxNode = NULL;
                tree.findMaxQuantity(tree.root, maxNode);
                cout << "Product with highest quantity:\nID: " << maxNode->productID << " | Quantity: " << maxNode->quantity << endl;
            }
        } 
        else if (choice == 5) break;
        else cout << "Invalid choice.\n";
    }
    return 0;
}
