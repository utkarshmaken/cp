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
vector<int> adj[maxn];
vector<ll> p(maxn),h(maxn),happ;
bool flag = true;
void find(int u, int pu){
    ll happd = 0,temp = p[u];
    for(auto v:adj[u]){
        if(v == pu) continue;
        find(v,u);
        p[u]+=p[v];
        happd+=happ[v];
    }
    if(p[u]<h[u]) flag =  false;
    if(h[u]+p[u] < 0) flag =  false;
    if((h[u] + p[u])&1) flag =  false;

    ll happi = (h[u] + p[u])/2;
    happ[u] = happi;
    if(happi < happd) flag = false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        happ.resize(n,0);flag = true;
        f(i,0,n) cin>>p[i];
        f(i,0,n) cin>>h[i];
        f(i,0,n-1){
            int u,v;
            cin>>u>>v;
            --u;--v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        
        find(0,-1);
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        f(i,0,n) adj[i].clear();

    }

}