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
const int maxn = 100001;
int main(){
    int n,k;
    cin>>n>>k;
    if(k>n){
        cout<<0<<endl;
        return 0;
    }
    n-=k;
    ll dp[n+1][k+1];
    memset(dp,0ll,sizeof(dp));
    rep(j,1,k) dp[0][j] = 1;
    rep(i,1,n){
        rep(j,1,k){
            if(i<j) dp[i][j] = dp[i][i]%mod;
            else dp[i][j] = (dp[i-j][j]+ dp[i][j-1])%mod;
        }
    }

    cout<<dp[n][k]%mod<<endl;
}
