/*Given a tree of n nodes, where each node i (1 ≤ i ≤ n) has 
ci coins attached with it. You have to choose a subset of 
nodes such that no two adjacent nodes (i.e. nodes connected 
directly by an edge) are chosen and sum of coins attached 
with nodes in chosen subset is maximum.*/
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
#define mp make_pair
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
using namespace std;
const int mod = 1000000007;

void dfs(vector<int> adj[], vector<pii>& dp,vector<int>& c, int u, int pu){
    for(int v:adj[u])
        if(v!=pu)
            dfs(adj,dp,c,v,u);
    
    int f = c[u],g = 0;
    for(int v:adj[u])
        if(v!=pu){
            f+=dp[v].se;
            g+=max(dp[v].fi,dp[v].se);
        }
    dp[u] = {f,g};
}
int main(){
    int n;
    cin>>n;
    vector<int> adj[n];
    vector<int> c(n);
    f(i,0,n-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    f(i,0,n) cin>>c[i];
    vector<pii> dp(n);
    dfs(adj,dp,c,0,-1);
    cout<<max(dp[0].fi,dp[0].se)<<endl;
}