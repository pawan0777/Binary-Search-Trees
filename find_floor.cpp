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

int findFloor(Node* root, int target){
    int ans = -1;
    while(root){
        if(root->val == target)
            return root->val;
        if(target > root->val){
            ans = root->val;
            root = root->right;
        }
        else
            root = root->left;
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
    cout<<findFloor(root, 7);
    return 0;
}