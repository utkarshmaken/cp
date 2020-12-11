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

ll mpow(ll x, ll y){
    ll res = 1;
    while(y!=0){
        if(y&1)
            res = (res*x)%mod;
        x = (x*x)%mod;
        y = y>>1;
    }
    return res;
}
int main(){
    ll dp[60];
    dp[0] = 1;
    rep(i,1,59){
        dp[i] = ( dp[i-1] + dp[i-1] + mpow(2,i)*mpow(10,i) ) % mod;
    }
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans = 0;
        ll res = 0;
        while(n!=0){
            ll k = 0;
            while((1<<k) <= n) ++k;
            --k;
            ans = ( ans + dp[k-1] + mpow(10,k))%mod;
            n-=(1<<k);
            res = (res + mpow(10,k)*n)%mod;
        }
        cout<<ans+res<<endl;
    }
}