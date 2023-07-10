#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* right;
    Node* left;

    Node(int data){
        val = data;
        right = NULL;
        left = NULL;
    }
};

Node* lcaBst(Node* root, Node* p, Node* q){
    if(root == nullptr)
        return nullptr;
    if(p->val < root->val and q->val < root->val)
        return lcaBst(root->left, p ,q);
    if(p->val > root->val and q->val > root->val)
        return lcaBst(root->right, p ,q);
    return root;
}

int main(){
    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right->left = new Node(13);
    Node* ans = lcaBst(root, root->left->right->left, root->left->right);
    cout<<ans->val<<endl;
    return 0;
}