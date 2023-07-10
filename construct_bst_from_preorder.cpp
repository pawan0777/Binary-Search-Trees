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

Node* constructBst(vector<int> preorder, int &i, int bound){
    if(i == preorder.size() || preorder[i] > bound)
        return nullptr;
    Node* root = new Node(preorder[i++]);
    root->left = constructBst(preorder, i, root->val);
    root->right = constructBst(preorder, i, bound);
    return root;
}

int main(){
    vector<int> preorder = {8,3,1,6,4,7,10,14,13};
    int i = 0;
    Node* root = constructBst(preorder, i, INT_MAX);
    printTree(root, nullptr, false);
    return 0;
}