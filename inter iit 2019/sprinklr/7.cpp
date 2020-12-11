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
ll fact[maxn];
ll inv_mod(ll x){
    ll ans = 1;
    ll y = mod-2;
    while(y > 0){
        if(y&1)
            ans = (ans*x)%mod;
        y = y>>1;
        x = (x*x)%mod;
    }
    return ans%mod;
}
ll comb(ll n, ll r){
    ll ans = fact[n];
    ans = (ans*inv_mod(fact[r]))%mod;
    ans = (ans*inv_mod(fact[n-r]))%mod;
    return ans;
}
int main(){
    int t;
    cin>>t;
    fact[0] = 1;fact[1] = 1;
    f(i,2,maxn) fact[i] = (fact[i-1]*i)%mod;
    while(t--){
        ll n,b,k;
        cin>>n>>b>>k;
        if(b<k || n-b<k-1){
            cout<<0<<endl;
            continue;
        }
        ll a1 = comb(b-1,k-1)%mod;
        ll a2 = comb(n-b+1,k)%mod;
        ll ans = (a1*a2)%mod;
        cout<<a1<<' '<<a2<<endl;
        cout<<ans<<endl;
    }
}