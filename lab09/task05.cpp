#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    int height;
    Node(int v){ val=v; left=right=nullptr; height=1; }
};

int h(Node* n){ return n? n->height:0; }
int bf(Node* n){ return n? h(n->left)-h(n->right):0; }

Node* rightRotate(Node* y){
    Node* x=y->left;
    Node* t=x->right;
    x->right=y;
    y->left=t;
    y->height=max(h(y->left),h(y->right))+1;
    x->height=max(h(x->left),h(x->right))+1;
    return x;
}

Node* leftRotate(Node* x){
    Node* y=x->right;
    Node* t=y->left;
    y->left=x;
    x->right=t;
    x->height=max(h(x->left),h(x->right))+1;
    y->height=max(h(y->left),h(y->right))+1;
    return y;
}

Node* insert(Node* node,int val){
    if(!node) return new Node(val);
    if(val<node->val) node->left=insert(node->left,val);
    else node->right=insert(node->right,val);
    node->height=max(h(node->left),h(node->right))+1;
    int balance=bf(node);
    if(balance>1 && val<node->left->val) return rightRotate(node);
    if(balance<-1 && val>node->right->val) return leftRotate(node);
    if(balance>1 && val>node->left->val){
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance<-1 && val<node->right->val){
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preorder(Node* r){
    if(!r) return;
    cout<<r->val<<" ";
    preorder(r->left);
    preorder(r->right);
}

int main(){
    Node* root=nullptr;
    root=insert(root,40);
    root=insert(root,30);
    root=insert(root,50);
    root=insert(root,25);
    root=insert(root,35);
    root=insert(root,45);
    root=insert(root,60);
    root=insert(root,55);
    preorder(root);
}

