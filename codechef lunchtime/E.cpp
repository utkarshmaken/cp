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
        vector<int> a(n);
        f(i,0,n) cin>>a[i];
        vector<int> adj[n];
        f(i,0,n-1){
            int u,v;
            cin>>u>>v;
            --u;--v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        sort(all(a));
        if(k==1){
            cout<<a[n-1]<<endl;
        }
        else{
            cout<<a[n-2] + (k-1)
        }

    }

}