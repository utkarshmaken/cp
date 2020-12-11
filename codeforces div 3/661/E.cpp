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
using namespace std;
const int mod = 1000000007;
const int maxn = 200000;
vector<pii> adj[maxn];
ll n,s;
vector<int> w(maxn);
vector<int> path;
int moves = 0;
void dfs(int u, int pu){
    for(auto p:adj[u]){
        int v = p.fi;
        if(v!=pu){
            w[v] = p.se;
            dfs(v,u);
        }
    }
}
void dfs1(int u, int pu, ll sum){
    sum+=w[u];
    if(sz(adj[u]) == 1){
        if(sum<=s){
            sum-=w[u];
            return;
        }
        path.pb(u);
        
        

        


    }
    for(auto p:adj[u]){
        int v = p.fi;
        if(v!=pu){
            path.pb(v);
            sum+=w[v];
            dfs1(v,u,sum);
            path.pop_back();
            sum-=w[v];
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>s;
        f(i,0,n-1){
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }
        path.pb(1);
        dfs(1,0);
        dfs1(1,0,0);





    }

}