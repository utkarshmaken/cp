#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    int color;
    static TreeNode* orig_root;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    bool nil;
    TreeNode(int x){
        data = x;
        color = 1;
        left  = NULL;
        right = NULL;
        parent = NULL;
        nil = false;
    }
    void LeftRotate(TreeNode *x){

    }
    void RightRotate(TreeNode* x){

    }
    TreeNode* uncle(TreeNode *z){
        TreeNode *x = z->parent;
        if(x->parent == NULL) return NULL;
        if(x == x->parent->left)
            return x->parent->right;
        if(x == x->parent->right)
            return x->parent->left;
    }

    void fixup(TreeNode *z, TreeNode *x){
        TreeNode *u = uncle(z);
        TreeNode *y = x->parent;
        if(u != NULL && u->color == 0){
            x->color = 1;
            u->color = 1;
            y->color = 0;
            if(y == y->orig_root)
                y->color = 1;
            else if(y->parent && y->parent->color == 0)
                fixup(y,y->parent);
            return;
        }

        if(x == y->left && z == x->left){
            RightRotate(y);
            x->color = 1;
            y->color = 0;
            return;
        }
        if(x == y->right && z == x->right){
            LeftRotate(y);
            x->color = 1;
            y->color = 0;
            return;
        }
        if(x == y->left && z == x->right){
            LeftRotate(x);
            Fixup(x,x->parent);

        }
    }

    TreeNode* insert(TreeNode *root, TreeNode *newNode){
        if(root == NULL)
            return newNode;
        if(newNode->data < root->data){
            root->left = insert(root->left,newNode);
            if(root->color == 0 && root->left->color == 0)
                fixup(root->left,root);
        }
        else if(newNode->data >= root->data){
            root->right = insert(root->right,newNode);
            if(root->color == 0 && root->right->color == 0)
                fixup(root->right, root);
        }
        return root;
    }

    void inorder(TreeNode *root){
        if(root->left)
            inorder(root->left);
        cout<<root->data<<endl;
        if(root->right)
            inorder(root->right);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin>>arr[i];
    TreeNode *root = new TreeNode(arr[0]);
    root->orig_root = root;
    for(int i = 1; i < n; i++){
        TreeNode *newNode = new TreeNode(arr[i]);
        newNode->color = 0;
        root = root->insert(root,newNode); 
    }
    root->inorder(root);
}