//LEXOGRAPHICALLY SMALLER TOPOLOGICAL SORT
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

int main(){
    int n,m;cin>>n>>m;
    vector<pii> edges(m);
    f(i,0,m) cin>>edges[i].fi>>edges[i].se;
    vector<int> adj[n];
    f(i,0,m)
        adj[edges[i].se].pb(edges[i].fi);
    vector<int> indegree(n);
    for(auto &p:edges)
        ++indegree[p.fi];
    set<int> s;
    vector<int> ans;
    f(i,0,n)
        if(indegree[i] == 0)
            s.insert(i);
    while(!s.empty()){
        int u = *s.begin();
        s.erase(s.begin());
        ans.pb(u);
        for(auto &v:adj[u]){
            --indegree[v];
            if(indegree[v] == 0)
                s.insert(v);
        }
    }
    for(auto &x:ans) cout<<x<<' ';
    cout<<endl;
    

    

    
}