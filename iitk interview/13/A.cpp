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
    ll l,m;
    cin>>l>>m;
    ll dp[l+1][m];
    memset(dp,0ll,sizeof(dp));
    rep(i,1,l-1){
        f(v,0,m-1){
            dp[i][v] = 1;
            f(v1,0,(v*v+1)%m)
                dp[i][v]+=dp[i-1][v1];
        }
    }
    ll ans = 1;
    f(i,0,5%m)
        ans+=dp[l-1][i];
    cout<<ans%m<<endl;
}