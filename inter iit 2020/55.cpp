//CHRISTMAS TREE
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
ll dp[maxn][21];
int n,m;

void dfs(int u, int pu){
    if(pu!=-1 && adj[u].size()==1){
        rep(i,1,m) dp[u][i] = 1;
        return;
    }
    for(auto v:adj[u]){
        if(v!=pu){
            dfs(v,u);
        }
    }
    rep(g,1,m){
        ll tot = 0;
        rep(i,1,m){
            ll mul = 1;
            for(auto v:adj[u]){
                if(v!=pu){
                    ll sum = 0;
                    rep(j,1,m)
                        if(__gcd(i,j) == g)
                            sum = (sum+dp[v][j])%mod;
                    mul = (mul*sum)%mod;
                }
            }
            tot = (tot + mul)%mod;
        }
        dp[u][g] = (dp[u][g] + tot)%mod;
    }
}
int main(){
    cin>>n>>m;
    f(i,0,n-1){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    } 
    memset(dp,0,sizeof(dp));
    dfs(0,-1);
    ll total = pow(m,n);
    ll gcd_one = dp[0][1];
    ll ans = total - gcd_one;
    ans = (ans+mod)%mod;
    cout<<ans<<endl;
    f(i,0,n)
        rep(j,1,m) cout<<dp[i][j]<<" \n"[j==m];
}