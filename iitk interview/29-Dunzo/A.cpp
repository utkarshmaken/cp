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
const int maxn = 100001;
vector<int> adj[maxn];
vector<int> val(maxn),prime(maxn,1),ans(maxn);

void findPrime(){
    prime[1] = 0;
    for(int p = 2;p*p<=maxn;p++){
        if(prime[p]){
            for(int i = p*p;i<=maxn;i+=p)
                prime[i] = 0;
        }
    }
}

int dfs(int u,int pu){
    ans[u] = prime[val[u]];
    int sum = 0;
    for(auto v:adj[u])
        if(v!=pu)
            sum+=dfs(v,u);
    ans[u]+=sum;
    return ans[u];
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> u(m),v(m);
    f(i,0,m) cin>>u[i];
    cin>>m;
    f(i,0,m) cin>>v[i];
    f(i,0,m){
        adj[u[i]].pb(v[i]);
        adj[v[i]].pb(u[i]);
    }
    cin>>n;
    rep(i,1,n) cin>>val[i];
    findPrime();
    dfs(1,0);
    
    int q;cin>>q;
    f(i,0,q){
        int x;
        cin>>x;
        cout<<ans[x]<<endl;
        
    }
}