//COLOURFUL TRAP
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
int n,m,k;
vector<int> ans;
vector<pii> adj[1000];
vector<int> color;
unordered_map<int,int> pos;
int res = INT_MAX;
void find(int curr, int final, int blue, int red, int dist){
    if(curr == final){
        if(abs(blue - red)<=k)
            res = min(res,dist);
    }
    int u = ans[curr];
    for(auto v:adj[u]){
        int ncurr = pos[v.fi];
        if(ncurr > final) continue;
        int nblue = blue,nred = red;
        if(color[v.fi] == 0) ++nblue;
        else ++nred;
        find(ncurr,final,nblue,nred,dist+v.se);
    }
}
int main(){
    cin>>n>>m>>k;
    color.resize(n);
    f(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        --u;--v;
        adj[u].pb({v,w});
    }
    f(i,0,n) cin>>color[i];
    vector<int> indegree(n);
    f(i,0,n){
        for(auto v:adj[i])
            ++indegree[v.fi];
    }
    queue<int> q;
    f(i,0,n)
        if(indegree[i] == 0)
            q.push(i);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.pb(u);
        for(auto v:adj[u]){
            --indegree[v.fi];
            if(indegree[v.fi] == 0)
                q.push(v.fi);
        }
    }
    
    f(i,0,n) pos[ans[i]] = i;
    int idx_0 = pos[0],idx_n = pos[n-1];
    int blue = 0,red = 0;
    if(color[0] == 0) ++blue;
    else ++red;
    find(idx_0,idx_n,blue,red,0);
    if(res == INT_MAX) cout<<-1<<endl;
    else cout<<res<<endl;
    
}