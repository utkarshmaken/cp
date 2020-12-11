//WEEKEND PLANNING
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
    int n,m,k;
    cin>>n>>m>>k;
    vector<pii> adj[n];
    f(i,0,m){
        int u,v,c;
        cin>>u>>v>>c;
        --u;--v;
        adj[u].pb({v,c});
        adj[v].pb({u,c});
    }
    vector<int> dist(n,INT_MAX);
    vector<vector<bool>> visited(n,vector<bool>(k+1));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
    pq.push({0,0,k});dist[0] = 0;
    while(!pq.empty()){
        vector<int> v = pq.top();
        pq.pop();
        int d = v[0],u = v[1],krem = v[2];
        if(visited[u][krem]) continue;
        visited[u][krem] = true;
        for(auto &p:adj[u]){
            if(p.fi == 0) continue;
            if(dist[p.fi] > d+p.se)
                dist[p.fi] = d+p.se;

            pq.push({d+p.se,p.fi,krem});

            if(krem>0){
                if(dist[p.fi] > d)
                    dist[p.fi] = d;
                pq.push({d,p.fi,krem-1});
            }
        }
    }
    for(auto &x:dist) cout<<x<<' ';



}