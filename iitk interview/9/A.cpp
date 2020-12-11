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
int find(ll x){
    int ans = 0;
    while(x>0){
        ans+=(x&1);
        x = x>>1;
    }
    return ans;
}
int main(){
    ll total;cin>>total;
    int n;cin>>n;
    int m;cin>>m;
    vector<pll> arr(n);
    f(i,0,n) cin>>arr[i].fi>>arr[i].se;
    sort(all(arr));
    ll start = 1;
    ll ans = 0;
    f(i,0,n){
        ll l = arr[i].fi,r = arr[i].se;
        ll x = l - start;
        ans+=find(x);
        start = r+1;

    }
    if(start <= total) ans+=find(total-start+1);
    cout<<ans<<endl;
}