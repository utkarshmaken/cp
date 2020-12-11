//NODE DISCOVERY ALGORITHM
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
    int n,e,l;cin>>n>>e>>l;
    vector<int> adj[n];
    f(i,0,e){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> L(l);
    f(i,0,l) cin>>L[i];
    vector<int> dist(n);
    vector<bool> visited(n,false);
    queue<int> q;
    q.push(0);dist[0] = 0;
    visited[0] = true;
    while(!q.empty()){
        for(int rep = q.size();rep>0;--rep){
            int u = q.front();
            q.pop();
            for(auto &v:adj[u]){
                if(visited[v]) continue;
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    int ans = 0;
    for(auto &v:L) ans = max(ans,dist[v]);
    cout<<ans<<endl;
}