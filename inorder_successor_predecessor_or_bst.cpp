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

Node* successor(Node* root, int num){
    Node* ans = nullptr;
    while(root){
        if(num >= root->val)
            root = root->right;
        else{
            ans = root;
            root = root->left;
        }
    }
    return ans;
}

Node* predecessor(Node* root, int num){
    Node* ans = nullptr;
    while(root){
        if(num <= root->val)
            root = root->left;
        else{
            ans = root;
            root = root->right;
        }
    }
    return ans;
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
    Node* ans = predecessor(root, 8);
    cout<<"Predecessor: "<<ans->val<<endl;
    return 0;
}