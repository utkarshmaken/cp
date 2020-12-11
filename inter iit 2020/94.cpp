//POSTORDER TRAVERSAL USING 2 STACKS
#include <bits/stdc++.h> 
using namespace std;

struct Node { 
  
    int data; 
    Node *left, *right; 
}; 
  
// Function to create a new node with the given data 
Node* newNode(int data) 
{ 
    Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 

void postOrderIterative(Node* root){ 
    stack<Node*> s1;
    stack<int> s2;
    s1.push(root);
    while(!s1.empty()){
        Node* f = s1.top();
        s1.pop();
        s2.push(f->data);
        if(f->left) s1.push(f->left);
        if(f->right) s1.push(f->right);
    }
    while(!s2.empty()){
        cout<<s2.top()<<endl;
        s2.pop();
    }
}
int main()
{ 
    // Let us construct the tree 
    // shown in above figure 
    Node* root = NULL; 
    root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
  
    postOrderIterative(root); 
  
    return 0; 
} 