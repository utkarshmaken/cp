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

int main(){
    int t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        ll rootx = sqrt(x);
        ll ans = 0;
        rep(k,1,rootx){
            ll bmin = k+1, bmax = min(y,x/k - 1);
            ans += max(0ll,bmax-bmin+1);
        }
        cout<<ans<<endl;
    }

}