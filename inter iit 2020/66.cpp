//QUADEYE GRAPH
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

int main(){
    int n,m;
    cin>>n>>m;
    vector<pii> adj[n];
    f(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    vector<int> time(n);
    f(i,0,n) cin>>time[i];
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    vector<int> dist(n,INT_MAX);
    vector<bool> visited(n,false);
    pq.push({0,0});dist[0] = 0;
    while(!pq.empty()){
        int d = pq.top().fi, u = pq.top().se;
        pq.pop();
        if(visited[u])
            continue;
        visited[u] = true;
        for(auto p:adj[u]){
            if(dist[p.fi] > d + p.se){
                if(time[p.fi] > d + p.se){
                    dist[p.fi] = d + p.se;
                    pq.push({dist[p.fi],p.fi});
                }
            }
        }
    }
    for(auto &x:dist)
        if(x == INT_MAX)
            x = -1;
    for(auto &x:dist)
        cout<<x<<" ";


}