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
vector<int> adj[maxn];
vector<int> adj_r[maxn];
vector<int> comp;
void fill(int u, vector<bool> &visited, stack<int> &s){
    visited[u] =  true;
    for(auto &v:adj[u])
        if(!visited[v])
            fill(v,visited,s);
    s.push(u);
}
void dfs(int u, vector<bool> &visited){
    visited[u] = true;
    comp.push_back(u);
    for(auto v:adj_r[u])
        if(!visited[v])
            dfs(v,visited);
}
int main(){
    int n;cin>>n;
    vector<int> cost1(n+1),cost2(n+1);
    rep(i,0,n) cin>>cost1[i];
    rep(i,0,n) cin>>cost2[i];
    int m;cin>>m;
    f(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj_r[v].pb(u);
    }
    stack<int> s;
    vector<bool> visited(n,false);
    f(i,0,n)
        if(!visited[i])
            fill(i,visited,s);
    visited = vector<bool>(n,false);
    int u = s.top();
    dfs(u,visited);
    int ans = INT_MAX;
    for(auto &x:comp)
        ans = min(ans,)


    
    




}