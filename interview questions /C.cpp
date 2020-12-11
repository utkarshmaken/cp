//https://leetcode.com/discuss/interview-question/584214/
#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};
int ans = 0;
bool find(TreeNode* root){
    if(root==NULL){
        return true;
    }
    if(!root->left && !root->right){
        ++ans;
        return true;
    }
    bool l = find(root->left);
    bool r = find(root->right);
    if(l && r){
        if((!root->left || root->left->val==root->val) && (!root->right ||root->right->val==root->val)){
            ++ans;
            return true;
        }
        else
            return false;   
    }
    return false;

}

int main(){
    int n;
    cin>>n;
    if(n==-1){
        cout<<-1<<endl;
        return 0;
    }
    vector<int> levels[11];
    int x;
    for(int i = 0;i<n+1;i++){
        for(int j = 0;j<(1<<i);j++){
            cin>>x;
            levels[i].push_back(x);
        }
    }
    
    TreeNode* root = new TreeNode(levels[0][0]);
    queue<TreeNode*> q;q.push(root);
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<levels[i].size();j+=2){
           TreeNode* temp = q.front();
           q.pop();
           TreeNode* l = new TreeNode(levels[i][j]);
           TreeNode* r = new TreeNode(levels[i][j+1]);
           if(l->val!=-1) temp->left = l;
           if(r->val!=-1) temp->right = r;
           q.push(l);q.push(r);
        }
    }
    TreeNode* temp = root;
    find(temp);
    cout<<ans<<endl;
}