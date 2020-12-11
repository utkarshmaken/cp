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
        int n;
        cin>>n;
        if(n==0){
            cout<<0<<endl;
            return 0;
        }
        vector<ll> pos(n),h(n);
        f(i,0,n) cin>>pos[i];
        cin>>n;
        f(i,0,n) cin>>h[i];
        vector<pll> arr;
        f(i,0,n) arr.pb({pos[i],h[i]});
        sort(all(arr));
        f(i,0,n){
            pos[i] = arr[i].fi;
            h[i] = arr[i].se;
        }
        ll ans = 0;
        f(i,0,n-1){
            ll hh1 = h[i],hh2 = h[i+1],x = pos[i+1]-pos[i]-1;
            ll h1 = min(hh1,hh2);
            ll h2 = max(hh1,hh2);
            if(x>0){
                    if(h1+x<=h2+1)
                        ans = max(ans,h1+x);
                    else
                    {
                        ll z = h2+1-h1;
                        ans = max(ans,h2+1+(x-z)/2);
                    }
                
            }
        }
        cout<<ans<<endl;
}