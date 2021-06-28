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
const ll mod =  998244353;
const int maxn = 100001;

ll gcdExtended(ll a, ll b, ll* x, ll* y){ 
    if (a == 0){ 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; 
    ll gcd = gcdExtended(b % a, a, &x1, &y1); 
    *x = y1 - (b / a) * x1; 
    *y = x1; 
    return gcd; 
} 

ll modInverse(ll a, ll m) { 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    ll res = (x % m + m) % m; 
    return res;
} 

ll power(ll x, ll y){
    ll res = 1;
    while(y != 0){
        if(y & 1)
            res = (res * x) % mod;
        x = (x*x) % mod;
        y = y>>1;
    }
    return res % mod;
}

int main(){
    ll m,n,k;
    cin>>m>>n>>k;
    if(m == 1){
        ll num = (k*n - (n-1)) % mod;
        ll inv = power(k,mod-2) % mod;
        ll ans = (num*inv) % mod;
        cout<<ans<<endl;
    }
    else{
        ll k2 = power(k,2);
        ll k3 = power(k,3);
        ll num = (((2*n) % mod)*k3)%mod;
        num = (num - k2 + mod) % mod;
        num = (num - (n-1)*(3*k2 - 1)%mod + mod) % mod;
        ll inv =  power(k3,mod-2) % mod;
        inv = (inv + mod) % mod;
        ll ans = (num*inv) % mod;
        cout<<ans<<endl;
    }
}