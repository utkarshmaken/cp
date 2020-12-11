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
vector<pii> adj[maxn];
vector<bool> ans(maxn),visited(maxn);
int n,e,mini;
map<pii,int> m;
bool dfs(int u, int dist){
    if(dist > mini) return false;
    if(u==n) return dist==mini;
    visited[u] = true;
    bool flag = false;
    for(auto p:adj[u]){
        if(!visited[p.fi])
            if(dfs(p.fi,dist + p.se)){
                ans[m[{u,p.fi}]] = true;
                flag = true;
            }
    }
    visited[u] = false;
    return flag;
}
int main(){
    scanf("%d%d",&n,&e);
    f(i,0,e){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        m[{u,v}] = i;
        m[{v,u}] = i;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    
    vector<int> d(n+1,INT_MAX);
    vector<bool> visited(n+1,false);
    d[1] = 0;
    priority_queue<pii, vector<pii> ,less<pii> > pq;
    pq.push({d[1],1});
    while(!pq.empty()){
        int v = pq.top().se;
        pq.pop();
        if(visited[v]) continue;
        visited[v] = true;
        for(auto p:adj[v]){
            if(d[p.fi] > d[v] + p.se){
                d[p.fi] = d[v] + p.se;
                pq.push({d[p.fi],p.fi});
            }
        }
    }
    mini = d[n];
  
    dfs(1,0);
    f(i,0,e){
        if(ans[i]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

}