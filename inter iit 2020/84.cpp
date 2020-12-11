//MAXIMUM COMMON CANDIES
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

void dfs(int u, vector<pii> adj[], vector<bool> &visited, set<int> &comp, int &x) {
    visited[u] = true;
    comp.insert(u);
    for(auto &p:adj[u])
        if(!visited[p.fi] && p.se == x)
            dfs(p.fi,adj,visited,comp,x);
}

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    vector<int> from(m),to(m),weight(m);
    f(i,0,m) cin>>from[i];
    cin>>m;
    f(i,0,m) cin>>to[i];
    cin>>m;
    f(i,0,m) cin>>weight[i];
    vector<pii> adj[n+1];
    set<int> candies;
    f(i,0,m){
        int u = from[i], v = to[i], w = weight[i];
        adj[u].pb({v,w});
        adj[v].pb({u,w});
        candies.insert(w);
    }
    int ans = 0;
    for(int x:candies){
        set<int> comp;
        vector<bool> visited(n+1,false);
        rep(i,1,n)
            if(!visited[i]){
                comp.clear();
                dfs(i,adj,visited,comp,x);
                if(comp.size() < 2) continue;
                auto it = comp.end();
                --it;
                int a1 = *it;
                --it;
                int a2 = *it;
                ans = max(ans, a1*a2);

            }
    }
    cout<<ans<<endl;
}