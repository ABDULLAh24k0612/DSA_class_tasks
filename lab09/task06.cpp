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

Node* minNode(Node* n){
    while(n->left) n=n->left;
    return n;
}

Node* deleteNode(Node* root,int key){
    if(!root) return root;
    if(key<root->val) root->left=deleteNode(root->left,key);
    else if(key>root->val) root->right=deleteNode(root->right,key);
    else{
        if(!root->left || !root->right){
            Node* temp=root->left? root->left : root->right;
            if(!temp){ temp=root; root=nullptr; }
            else *root=*temp;
            delete temp;
        }else{
            Node* temp=minNode(root->right);
            root->val=temp->val;
            root->right=deleteNode(root->right,temp->val);
        }
    }
    if(!root) return root;
    root->height=max(h(root->left),h(root->right))+1;
    int balance=bf(root);
    if(balance>1 && bf(root->left)>=0) return rightRotate(root);
    if(balance>1 && bf(root->left)<0){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance<-1 && bf(root->right)<=0) return leftRotate(root);
    if(balance<-1 && bf(root->right)>0){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void preorder(Node* r){
    if(!r) return;
    cout<<r->val<<" ";
    preorder(r->left);
    preorder(r->right);
}

int main(){
    Node* root=nullptr;
    root=insert(root,100);
    root=insert(root,80);
    root=insert(root,120);
    root=insert(root,70);
    root=insert(root,90);
    root=insert(root,110);
    root=insert(root,130);
    root=deleteNode(root,80);
    preorder(root);
}
