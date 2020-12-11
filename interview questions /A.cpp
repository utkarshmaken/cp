//https://leetcode.com/discuss/interview-question/584289/
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
vector<int> find(TreeNode* root, int &k){
    if(root==NULL){
        return vector<int>();
    }
    if(!root->left && !root->right){
        vector<int> a(1);
        return a;
    }
    vector<int> l = find(root->left,k);
    vector<int> r = find(root->right,k);
    for(auto &x:l) ++x;
    for(auto &x:r) ++x;
    for(auto &x:l)
        for(auto &y:r)
            if(x+y<=k) ans++;
    l.insert(l.end(),r.begin(),r.end());
    return l;
}
void dfs(TreeNode* temp){
    if(!temp) return;
    cout<<temp->val<<endl;
    dfs(temp->left);dfs(temp->right);
}
int main(){
    int k,n;
    cin>>k>>n;
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
    find(temp,k);
    cout<<ans<<endl;
}