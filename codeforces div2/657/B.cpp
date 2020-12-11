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
    int t;
    cin>>t;
    while(t--){
        ll l,r,m;
        cin>>l>>r>>m;
        ll low = m - (r-l);
        ll high = m + (r-l);
        rep(i,l,r){
            ll div = low/i;
            if(div==0 || low%i!=0)
                div++;
            if(div*i<=high){
                ll num = m - i*div;
                if(num<0)
                    cout<<i<<' '<<r+num<<' '<<r<<endl;
                else
                    cout<<i<<' '<<l + num<<' '<<l<<endl;
                break;
            }
        }
        
    }

}