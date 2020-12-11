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
    int n;cin>>n;
    vector<int> roll(7);
    rep(i,1,6) cin>>roll[i];
    ll dp[n+1][7];
    memset(dp,0ll,sizeof(dp));
    rep(i,1,6) dp[1][i] = 1;
    dp[1][0] = 6;
    rep(i,2,n){
        ll sum = 0;
        rep(j,1,6){
                dp[i][j]= dp[i-1][0];
            if(i-roll[j]<1){}
            else if(i-roll[j]==1)
                dp[i][j] = (dp[i][j]-1)%mod;
            else
                dp[i][j] = ((dp[i][j] - (dp[i-roll[j]-1][0] - dp[i-roll[j]-1][j]))%mod + mod)%mod;
            sum = (sum+dp[i][j])%mod;
        }
        dp[i][0] = sum;
    }
    ll ans = dp[n][0];
    cout<<ans<<endl;

}