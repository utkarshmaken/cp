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
        ll n;
        cin>>n;
        int rootn = pow(2*n,0.5);
        vector<int> factors;
        rep(i,2,rootn)
            if(2*n % i ==0)
                factors.pb(i);
        ll ans = 0;
        for(auto x:factors){
            if( (2*n/x-(x-1))>=2 && !((2*n/x-(x-1))&1) )
                ans++;
        }
        cout<<ans<<endl;
}