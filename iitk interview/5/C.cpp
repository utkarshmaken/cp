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
vector<pii> adj[101];
map<pii,int> m;
vector<int> comp;
void dfs(int u, vector<bool> &visited, int &w){
    visited[u] =true;
    comp.pb(u);
    for(auto p:adj[u])
        if(!visited[p.fi] && p.se==w)
            dfs(p.fi,visited,w);
}
int main(){
    int n,e;
    cin>>n>>e;
    set<int> intr;
    f(i,0,e){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
        intr.insert(w);
    }
    for(auto w:intr){
        vector<bool> visited(n+1);
        rep(i,1,n){
            comp.clear();
            if(!visited[i]){
                dfs(i,visited,w);
                f(i,0,sz(comp)){
                    f(j,i+1,sz(comp)){
                        int u = comp[i],v = comp[j];
                        if(u>v) swap(u,v);
                        m[{u,v}]++;
                    }
                }

            }
        }
    }
   int maxi = 0,ans = 0;
   for(auto it:m){
        if(it.se>maxi)
            maxi = it.se;       
    }
    for(auto it:m){
        if(it.se==maxi)
            ans = max(ans,it.fi.fi * it.fi.se);
    }
    
    cout<<ans<<endl;
}