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
const int maxn = 100001;

int main(){
    ll n,d,m;
    cin>>n>>d>>m;
    vector<ll> a(n);
    f(i,0,n) cin>>a[i];
    sort(all(a));
    ll s = 0;
    f(i,0,n) s+=a[i];
    auto it = upper_bound(all(a),m);
    if(it==a.end()){
        cout<<s<<endl;
        return 0;
    }
    ll idx = it-a.begin();
    ll grt = n-idx,less = idx;
    vector<ll> sum_g(grt+1),sum_l(less+1);
    repd(i,n-1,idx) sum_g[n-i] = sum_g[n-i-1] + a[i];
    repd(i,idx-1,0) sum_l[idx-i] = sum_l[idx-i-1] + a[i];
    
    ll ans = 0;
    rep(i,1,grt){
        if(grt-i > i*d) continue;
        ll req = (i-1)*d;
        req-=grt-i;
        req = max(0ll,req);
        ll j = less - req;
        if(j<0) continue;
        ans = max(ans,sum_g[i] + sum_l[j]);
    }
    cout<<ans<<endl;

}