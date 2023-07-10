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

// bool ans = true;
// void checkValidBst(Node* root, int low, int high){
//     if(root == nullptr)
//         return;
//     if(root->val >= high or root->val <= low){
//         ans = false;
//         return;
//     }
//     checkValidBst(root->left, low, root->val);
//     checkValidBst(root->right, root->val, high);
// }

bool checkValidBst(Node* root, int low, int high){
    if(root == nullptr)
        return true;
    if(root->val >= high or root->val <= low)
        return false;
    return checkValidBst(root->left, low, root->val) and checkValidBst(root->right, root->val, high);
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
    cout<<checkValidBst(root, INT_MIN, INT_MAX);
    // cout<<ans;
    return 0;
}