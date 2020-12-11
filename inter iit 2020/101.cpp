//CITY ATTRACTIONS
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
const ll mod = 1000000007;
const int maxn = 1e5;
int ans = 0;
void dfs(vector<pii> adj[], int u, vector<int> &beauty, vector<bool> &visited, int curr_b, int curr_t, int &max_t){
    if(u == 0 && curr_b > 0){
        ans = max(ans,curr_b);
        return;
    }
    
    for(auto &p:adj[u]){
        int v = p.fi, w = p.se;
        if(curr_t + w <= max_t){
            if(visited[v])
                dfs(adj,v,beauty,visited,curr_b,curr_t+w,max_t);
            else{
                visited[v] = true;
                dfs(adj,v,beauty,visited,curr_b+beauty[v],curr_t+w,max_t);
                visited[v] = false;
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    int max_t;
    cin>>max_t;
    vector<int> beauty(n);
    cin>>n;
    f(i,0,n) cin>>beauty[i];
    vector<int> to(m),from(m),weight(m);
    cin>>m; f(i,0,m) cin>>from[i];
    cin>>m; f(i,0,m) cin>>to[i];
    cin>>m; f(i,0,m) cin>>weight[i];
    vector<pii> adj[n];
    f(i,0,m){
        int u = from[i], v  = to[i], w = weight[i];
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    vector<bool> visited(n,false);
    dfs(adj,0,beauty,visited,0,0,max_t);
    cout<<ans<<endl; 
}