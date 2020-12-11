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
const int maxn = 2000000;
vector<int> adj[maxn+1];
vector<bool> visited(maxn+1);
int dfs(int u){
    int ans = 0;
    visited[u] = true;
    for(auto v:adj[u])
        if(!visited[v])
            ans = max(ans,dfs(v));
    ans++;
    visited[u] = false;
    return ans;
    
}
int main(){
    int s,e;
    scanf("%d%d",&s,&e);
    vector<int> indegree(s+1);
    f(i,0,e){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].pb(v);
        indegree[v]++;
    }
    vector<int> zero;
    rep(i,1,s){
        if(indegree[i] == 0)
            zero.pb(i);
    }
    int maxi = 0;
    
    for(auto u:zero)
        maxi = max(maxi,dfs(u));
    printf("%d\n",maxi);

}