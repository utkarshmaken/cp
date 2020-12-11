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

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        set<int> adj[n];
        vector<int> root[n];
        int a,b;
        f(i,0,n-1){
            cin>>a>>b;
            --a;--b;
            adj[a].insert(b);
            adj[b].insert(a);
        }
        if(k==1){
            cout<<n-1<<endl;
            continue;
        }
        f(i,0,n)
            if(sz(adj[i]) == 1)
                root[*adj[i].begin()].pb(i);
        queue<int> grt;
        f(i,0,n)
            if(sz(root[i])>=k)
                grt.push(i);
        int ans = 0;
        while(!grt.empty()){
           int u = grt.front();
           grt.pop();
           int mul = sz(root[u])/k;
           f(i,0,mul*k){
                int v = root[u].back();
                root[u].pop_back();
                adj[u].erase(v);
                adj[v].erase(u);
           }
           ans+=mul;

            if(root[u].empty() && sz(adj[u])==1){
                int p = *adj[u].begin();
                root[p].pb(u);
                if(sz(root[p])==k)
                    grt.push(p);
            }

        }
        cout<<ans<<endl;
        
    }

}