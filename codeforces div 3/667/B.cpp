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
    int t;cin>>t;
    while(t--){
        ll a,b,x,y,n;
        cin>>a>>b>>x>>y>>n;
        ll aa = a,bb = b,nn=n;
        ll ans = 1e18;
           int t = min({n,a-x});
           n-=t;a-=t;
           if(n==0) ans = min(ans,a*b);
           else if(a==x){
               int t = min({n,b-y});
               n-=t;b-=t;
               ans = min(ans,a*b);
           }
           
        
        a=aa;b=bb;n=nn;
            t = min({n,b-y});
            n-=t;b-=t;
            if(n==0) ans = min(ans,a*b);
            else if(b==y){
               int t = min({n,a-x});
               n-=t;a-=t;
               ans = min(ans,a*b);
            }
        cout<<ans<<endl;
    }

}