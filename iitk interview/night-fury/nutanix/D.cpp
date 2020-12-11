//maximum matches
//given n players and m pairs with matches 
//between them,assign them to 2 teams such that 
//maximum matches can be conducted in the order given
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
const int maxn = 100001;
 
int main(){
    int n,m;
    cin>>n>>m;
    vector<pii> arr(m);
    f(i,0,m) cin>>arr[i].fi>>arr[i].se;
    
    vector<pii> adj[n+1];
    f(i,0,m){
        adj[arr[i].fi].pb({arr[i].se,i});
        adj[arr[i].se].pb({arr[i].fi,i});
    }
    vector<int> color(n);
    int maxi = m-1;
    cout<<maxi+1<<endl;
}