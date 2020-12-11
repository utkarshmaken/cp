//CLOSEST LEAF IN A BINARY TREE
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
 
#define f(i,a,b) for(int i = a;i<b;i++)
#define rep(i,a,b) for(int i = a;i<=b;i++)
#define fd(i,a,b) for(int i = a;i>b;i--)
#define repd(i,a,b) for(int i = a;i>=b;i--)
 
#define pii pair<int,int>
#define pll pair<ll,ll>
 
#define fi first
#define se second
#define pb push_back
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
#define endl '\n'
using namespace std;
const int mod = 1000000007;
const int maxn = 1e5;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};
vector<pair<Node*,char>> anc;
int closestDown(Node* root){
    if(root == NULL)
        return INT_MAX;
    if(!root->left && !root->right)
        return 0;
    return 1+ min(closestDown(root->left),closestDown(root->right));
}
int find(Node* root, int k){
    if(root == NULL)
        return INT_MAX;
    if(root->val == k){
        int ans = closestDown(root);
        int len = anc.size();
        for(int i = len-1;i>=0;i--){
            int t;
            if(anc[i].se == 'l')
                t = closestDown(anc[i].fi->right);
            else
                t = closestDown(anc[i].fi->left);
            
            if(t!=INT_MAX)
                ans = min(ans,len-i+1+t); 
        }
        return ans;
    }
    anc.pb({root,'l'});
    int ans = find(root->left,k);
    anc.pop_back();
    anc.pb({root,'r'});
    ans = min(ans,find(root->right,k));
    return ans;
    
}
int main(){
    Node* root = new Node(1);
    Node* l1 = new Node(2);
    Node* r1 = new Node(3);
    root->left = l1;
    root->right = r1;
    Node* l2 = new Node(4);
    Node* r2 = new Node(5);
    r1->left = l2;
    r1->right = r2;
    Node* l3 = new Node(6);
    l2->left = l3;
    Node* r3 = new Node(7);
    r2->right = r3;
    Node* l4 = new Node(8);
    Node* r4 = new Node(9);
    l3->left = l4;
    l3->right = r4;
    Node* l5 = new Node(10);
    r3->left = l5;
    int k;cin>>k;
    int ans = find(root,k);
    cout<<ans<<endl;
}