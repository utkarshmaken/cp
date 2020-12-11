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
 
int main(){
    int speed;cin>>speed;
    int n;cin>>n;
    vector<pii> pos(n);
    f(i,0,n) cin>>pos[i].fi>>pos[i].se;
    ld time = 0;
    f(i,0,n){
        f(j,i+1,n){
            ld dist = sqrt( (pos[j].se - pos[i].se)*(pos[j].se - pos[i].se) + (pos[j].fi - pos[i].fi)*(pos[j].fi - pos[i].fi) );
            ld t = dist/speed;
            time = max(time,t);
        }
    }
    ll inte = floor(time);
    ll frac = (time-inte)*pow(10,7);
    int last = frac%10;
    if(last>=5) frac = frac/10 + 1;
    else frac = frac/10;
    ld f = frac/pow(10,6);
    ld ans = inte + f;
    printf("%.6Lf",ans);

}