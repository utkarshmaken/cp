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
const int maxn = 100001;
vector<int> adj[maxn];
ll dp1[maxn],dp2[maxn];
void dfs(int u, int pu){
    if(sz(adj[u])==1 && adj[u][0]==pu){
        dp1[u] = 1;
        dp2[u] = 0;
        return;
    }
    for(auto v:adj[u])
        if(v!=pu)
            dfs(v,u);
    ll a1 = 1,a2 = INT_MAX;
    bool flag = false;
    for(auto v:adj[u])
        if(v!=pu){
            a1+=min(dp1[v],dp2[v]);
            a2 = min(a2,dp1[v]-min(dp1[v],dp2[v]));
            if(dp2[v]==0) flag = true;
        }
    dp1[u] = a1;
    if(flag) dp2[u] = INT_MAX;
    else dp2[u] = a1-1+a2;
}
int main(){
   int n;
   cin>>n;
   int e;cin>>e;
   f(i,0,e){
       int u,v;
       cin>>u>>v;
       adj[u].pb(v);
       adj[v].pb(u);
    }
    dfs(1,0);
    cout<<min(dp1[1],dp2[1])<<endl;

}