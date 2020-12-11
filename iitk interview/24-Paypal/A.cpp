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
const int maxn = 4001;
vector<int> adj[maxn];
int mat[maxn][maxn];
int mini = INT_MAX;
int main(){
    int n,e,u,v;
    cin>>n>>e;
    rep(i,1,n)
        rep(j,1,n)
            mat[i][j] = 0;
    vector<pii> edge;
    f(i,0,e){
        cin>>u>>v;
        edge.pb({u,v});
        mat[u][v] = 1;adj[u].pb(v);
        mat[v][u] = 1;adj[v].pb(u);
    }
    for(auto p:edge){
        int u = p.fi,v = p.se;
        rep(i,1,n){
            if(mat[u][i] && mat[v][i])
                mini = min(mini,sz(adj[u]) + sz(adj[v]) + sz(adj[i]) - 6);
            
        }
    }
    if(mini ==INT_MAX)
        cout<<-1<<endl;
    else
        cout<<mini<<endl;

}