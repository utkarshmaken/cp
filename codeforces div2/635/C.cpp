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
const int maxn = 200001;
int n,k;
vector<int> adj[maxn];
vector<int> happi;
int dfs(int u, int pu,int depth){
    int num = 1;
    for(auto v:adj[u])
        if(v!=pu)
            num+=dfs(v,u,depth+1);
    
    happi.pb(num - depth);
    return num;
}
int main(){
    cin>>n>>k;
    int u,v;
    f(i,0,n-1){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1,1);
    sort(all(happi),greater<int>());
    ll ans = 0;
    f(i,0,n-k)
        ans+=happi[i];
    cout<<ans<<endl;
}