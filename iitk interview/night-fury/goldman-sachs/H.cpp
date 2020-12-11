//VIRUS
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
const int maxn = 10001;
vector<int> adj[maxn];
vector<int> boost(maxn);

int dfs(int u){
    int ans = INT_MIN;
    for(auto &v:adj[u])
        ans = max(ans,dfs(v));
    cout<<ans<<endl;
    return max(boost[u],boost[u]+ans);
}

int main(){
    int n;
    cin>>n;
    vector<int> pre0;
    f(i,0,n){
        cin>>boost[i];
        int t,x;
        cin>>t;
        if(t==0) pre0.pb(i);
        f(j,0,t){
            cin>>x;
            --x;
            adj[x].pb(j);
        }
    }
    cout<<endl;
    f(i,0,n){
        for(auto &v:adj[i]) cout<<v<<' ';
        cout<<endl;
    }
    
    /*int ans = INT_MIN;
    for(auto &x:pre0)
        ans = max(ans,dfs(x));
    cout<<ans<<endl;*/
}