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
int ct = 0;
int ans = 0;

void kthSmallestNode(Node* root, int k){
    if(root == nullptr)
        return;
    kthSmallestNode(root->left, k);
    ct++;
    if(ct == k){
        ans = root->val;
        return;
    }
    kthSmallestNode(root->right, k);
}

void kthLargestNode(Node* root, int k){
    if(root == nullptr)
        return;
    kthLargestNode(root->right, k);
    ct++;
    if(ct == k){
        ans = root->val;
        return;
    }
    kthLargestNode(root->left, k);
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
    // kthSmallestNode(root, 3);
    kthLargestNode(root, 3);
    cout<<ans;
    return 0;
}