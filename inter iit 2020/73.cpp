//TREE PLAY

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
int lca[maxn][20];
int n,q,m;

void dfs(int u, int pu, vector<int> &stones, vector<int>& pre_xor, vector<int> &level){
    if(pu!=-1){
        pre_xor[u] = pre_xor[pu]^stones[u];
        lca[u][0] = pu;
        level[u] = 1 + level[pu];
    }

    for(auto &v:adj[u])
        if(v!=pu)
            dfs(v,u,stones,pre_xor,level);
}
int find_lca(int u, int v, vector<int> &level){
    if(level[u] < level[v])
        swap(u,v);
    int diff = level[u] - level[v];
    f(i,0,m)
        if((diff>>i)&1)
            u = lca[u][i];
    
    if(v==u)
        return u;

    repd(i,m-1,0){
        if(lca[u][i]!=-1 && lca[v][i]!=-1 && lca[u][i]!=lca[v][i]){
            u = lca[u][i];
            v = lca[v][i];
        }
    }
    return lca[u][0]; 
}

int main(){
    cin>>n>>q;
    vector<int> stones(n);
    f(i,0,n) cin>>stones[i];
    f(i,0,n-1){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> pre_xor(n),level(n);
    memset(lca,-1,sizeof(lca));
    pre_xor[0] = stones[0];
    level[0] = 0;
    dfs(0,-1,stones,pre_xor,level);
    m = ceil(log2(n)) + 1;
    f(j,1,m)
        f(i,0,n)
            if(lca[i][j-1]!=-1)
                lca[i][j] = lca[lca[i][j-1]][j-1];
    
    f(i,0,q){
        int u,v;
        cin>>u>>v;
        --u;--v;
        int w = find_lca(u,v,level);
        int nim = pre_xor[u]^pre_xor[v]^stones[w];
        if(nim == 0)
            cout<<"Alice"<<endl;
        else
            cout<<"Bob"<<endl;
    }
}