#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

map<int,vector<int>> ans;
void find(Node* root, int slope){
    if(!root) return;
    ans[slope].push_back(root->data);
    find(root->left,slope-1);
    find(root->right,slope);
}
void diagonalPrint(Node* root){
    find(root,0);
    for(auto it = ans.rbegin();it!=ans.rend();++it){
        vector<int> v = it->second;
        for(auto &x:v) cout<<x<<" ";
        cout<<endl;
    }
}
 
int main()
{
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    diagonalPrint(root);
 
    return 0;
}