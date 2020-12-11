//OPENING HOSPITALS
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
int dp[maxn][2];
void dfs(vector<int> adj[], int u, int pu){
    if(sz(adj[u]) == 1 && adj[u][0] == pu){
        dp[u][0] = 1;
        dp[u][1] = INT_MAX;
        return;
    }
    for(auto &v:adj[u])
        if(v!=pu)
            dfs(adj,v,u);
    bool f = false;
    int a1 = 0,a2 = 0,mini = INT_MAX;
    for(auto &v:adj[u])
        if(v!=pu){
            for(auto &w:adj[v])
                if(w!=u)
                    a1+=min(dp[w][0],dp[w][1]);
            if(dp[v][0]<=dp[v][1])
                f = true;
            a2 += min(dp[v][0],dp[v][1]);
            mini = min(mini,dp[v][0]-dp[v][1]);
        }
    dp[u][0] = 1 + a1;
    if(f) dp[u][1] = a2;
    else dp[u][1] = a2 + mini;
}
int main(){
    int n,m;cin>>n>>m;
    vector<int> adj[n];
    f(i,0,m){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    memset(dp,-1,sizeof(dp));
    dfs(adj,0,-1);
    cout<<min(dp[0][0], dp[0][1])<<endl;
}