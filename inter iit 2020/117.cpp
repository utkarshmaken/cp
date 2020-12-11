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
int ans;
int dfs(vector<int> adj[], int u, int pu){
    if(adj[u].size() == 1 && adj[u][0] == pu)
        return 1;
    int one = 0, more = 0;
    for(auto &v:adj[u])
        if(v != pu){
            int h = dfs(adj,v,u);
            if(h == 1) one++;
            else more++;
        }
    ans += more;
    if(more == 0) ++ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> adj[n];
        f(i,0,n-1){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        ans = 0;
        dfs(adj,0,-1);
        cout<<ans<<endl;
    }

}