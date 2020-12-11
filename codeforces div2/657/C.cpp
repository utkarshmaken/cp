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
vector<ll> x(maxn),y(maxn);
vector<pll> a(maxn),b(maxn);
bool compare(pll a, pll b){
    return a.fi > b.fi;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        f(i,0,m){
            cin>>x[i]>>y[i];
            a[i] = {x[i],i};b[i] = {y[i],i};
        }
        sort(all(a),compare);
        sort(all(b),compare);
        ll happi = 0,index = 0,tmax = 0;
        while(n>0 && index<m && a[index].fi>=b[0].fi){
            happi+=a[index].fi;
            tmax = max(tmax,y[a[index].se]);
            index++;n--;
        }

        ll op = tmax*n;
        while(index<m){
            ll op1 = a[index].fi + (n-1)*y[a[index].se];
            op = max(op,op1);
            index++;
        }
        happi+=op;
        cout<<happi<<endl;

    }

}