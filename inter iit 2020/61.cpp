//BUITTERFLY EFFECT
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
const int maxn = 1e5;
ll find(ll x, ll y){
    ll ans = 1;
    while(y!=0){
        if(y&1)
            ans = (ans*x)%mod;
        
        y = y>>1;
        x = (x*x)%mod;
    }
    return ans%mod;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,x,k;
        cin>>n>>k>>x;
        if(x > k){
            ll ans = (k*find(k-1,n))%mod;
            cout<<ans<<endl;
        }
        else{
            ll dp[n+1][k+1];
            rep(i,1,k) dp[1][i] = 1;
            dp[1][0] = k;
            rep(i,2,n){
                ll sum = 0;
                rep(j,1,k){
                    if(j!=x){
                        dp[i][j] = ((dp[i-1][0] - dp[i-1][j])%mod + mod)%mod;
                        sum = (sum + dp[i][j])%mod;
                    }
                    else{
                        dp[i][j] = dp[i-1][0]%mod;
                        sum = (sum + dp[i][j])%mod;
                    }
                }
                dp[i][0] = sum;
            }
            cout<<dp[n][0]<<endl;
        }
    }
}