//TRIPLETS WITH TARGET PRODUCT
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

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    f(i,0,n) cin>>arr[i];
    ll target;cin>>target;
    unordered_map<int,int> m;
    for(auto &x:arr) ++m[x];

    int ans = 0;
    f(i,0,n-1){
        ll u = arr[i],v = arr[i+1];
        if(target % (u*v) !=0) continue;
        ll w = target / (u*v);
        if(w!=u && w!=v)
            ans+=m[w];
        else if(w == u && u == v)
            ans+=m[w]-2;
        else if(w==u || w==v)
            ans+=m[w]-1;
    }
    f(i,0,n-2){
        ll u = arr[i],v = arr[i+1], w = arr[i+2];
        if(u*v*w == target) --ans;
    }
    cout<<ans<<endl;
}