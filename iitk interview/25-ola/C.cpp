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
    ll n,m,x,y;
    cin>>n>>m>>x>>y;
    ll ans = 0;ll buy = 0;
    while(n>0){
        if(n >= m/x){
            n-=m/x;
            ans = m/x;
            m = m - (m/x)*x;
            ll books = ceil(1.0*x/y);
            ll sell = (n*books)/(books+1);
            buy+=sell;
            n-=sell;m+=sell*y;
        }
        else{
            ans+= n;
            m-=n*x;
            n = 0;
        }
    }

    cout<<ans<<endl;

}