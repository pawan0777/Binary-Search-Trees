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

struct Trunk{
    Trunk *prev;
    string str;
 
    Trunk(Trunk *prev, string str){
        this->prev = prev;
        this->str = str;
    }
};

void showTrunks(Trunk *p){
    if (p == nullptr)
        return;
    showTrunks(p->prev);
    cout << p->str;
}
 
void printTree(Node* root, Trunk *prev, bool isLeft){
    if (root == nullptr)
        return;
 
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);
    printTree(root->right, trunk, true);

    if (!prev) 
        trunk->str = "---";
    else if (isLeft){
        trunk->str = ".---";
        prev_str = "   |";
    }
    else {
        trunk->str = "`---";
        prev->str = prev_str;
    }
    
    showTrunks(trunk);
    cout << " " << root->val << endl;
    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";
    printTree(root->left, trunk, false);
}

void insert(Node* root, int num){
    Node* curr = root;
    while(curr){
        if(num == curr->val)
            return;
        else if(num < curr->val){
            if(curr->left)
                curr = curr->left;
            else{
                curr->left = new Node(num);
                return;
            }
        }
        else{
            if(curr->right)
                curr = curr->right;
            else{
                curr->right = new Node(num);
                return;
            }
        }
    }
}

int main(){
    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    // root->left->left = new Node(1);
    // root->left->right = new Node(6);
    // root->right->right = new Node(14);
    // root->left->right->left = new Node(4);
    // root->left->right->right = new Node(7);
    // root->right->right->left = new Node(13);
    printTree(root, nullptr, false);
    insert(root, 6);
    insert(root, 9);
    insert(root, 10);
    insert(root, 4);
    printTree(root, nullptr, false);
    return 0;
}