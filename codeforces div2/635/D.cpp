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
const int maxn = 2000000;
ll ans = 9e18;
ll dist(ll &x, ll &y, ll &z){
    return (x-y)*(x-y) + (y-z)*(y-z) + (x-z)*(x-z);
}
void solve(vector<ll> &r, vector<ll> &g, vector<ll> &b){
    for(auto y:g){
        auto x = upper_bound(all(r),y);
        auto z = lower_bound(all(b),y);
        if(x == r.begin() || z==b.end()) continue;
        --x;
        ans = min(ans,dist(*x,y,*z));
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int nr,ng,nb;
        cin>>nr>>ng>>nb;
        vector<ll> r(nr),g(ng),b(nb);
        f(i,0,nr) cin>>r[i];
        f(i,0,ng) cin>>g[i];
        f(i,0,nb) cin>>b[i];
        sort(all(r));sort(all(g));sort(all(b));
        
        solve(r,g,b);solve(r,b,g);
        solve(g,r,b);solve(g,b,r);
        solve(b,g,r);solve(b,r,g);

        cout<<ans<<endl;
        ans = 9e18;
    }

}