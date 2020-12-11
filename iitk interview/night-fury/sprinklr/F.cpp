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
#define mp make_pair
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
#define endl '\n'
using namespace std;
const int mod = 1000000007;
const int maxn = 100001;

int main(){
    int n,m,k;cin>>n>>m>>k;
    vector<pii> adj[n];
    f(i,0,m){
        int u,v,c;
        cin>>u>>v>>c;
        --u;--v;
        adj[u].pb({v,c});
        adj[v].pb({u,c});
    }
    vector<int> dist(n,INT_MAX);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<bool>> visited(n,vector<bool>(k+1));
    dist[0] = 0;
    pq.push({0,0,k});
    while(!pq.empty()){
        vector<int> f = pq.top();
        int d = f[0],u = f[1],krem = f[2];
        pq.pop();
        if(visited[u][krem])
            continue;
        visited[u][krem] = true;
        for(auto &p:adj[u]){
            int v = p.fi,w = p.se;
            if(d + w < dist[v])
                dist[v] = d+w;
            pq.push({d+w,v,krem});
            
            if(krem>0){
                if(d < dist[v])
                    dist[v] = d;
                pq.push({d,v,krem-1});
            }
        }
    }
    for(int i = 0;i<n;i++)
        cout<<dist[i]<<' ';
}