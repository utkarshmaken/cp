//TREE DP
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
const int maxn = 2e5;
int ans = 0;
void dfs(vector<int> *adj, int u, int pu, vector<vector<int>> &dp){
    if(adj[u].size() == 1 && adj[u][0]==pu)
        return;
    int a1 = 0,a2 = 0,idx1,idx2;
    int b1 = -1,b2 = -1;

    for(auto v:adj[u]){
        if(v!=pu){
            dfs(adj,v,u,dp);
            if(dp[v][0] >= a1){
                b1 = a1;
                idx2 = idx1;
                a1 = dp[v][0];
                idx1 = v;
            }
            else if(dp[v][0] > b1){
                idx2 = v;
                b1 = dp[v][0];
            }
            
            if(dp[v][1] >= a2){
                b2 = a2;
                a2 = dp[v][1];
            }
            else if(dp[v][1] > b2)
                b2 = dp[v][1];
        }
    }
    dp[u][0] = 1+a1;
    dp[u][1] = max(1 + a1 + (a2==-1?0:a2), b1);
    if(b2!=-1) ans = max(ans,b1*b2);
    if(a2!=-1) ans = max(ans,a1*(1+a2));

}
int main(){
    int n;
    cin>>n;
    vector<int> adj[n];
    f(i,0,n-1){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<vector<int>> dp(n,vector<int>(2,0));
    dfs(adj,0,-1,dp);
    cout<<ans<<endl;
}
