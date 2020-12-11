//WAYS TO SUM

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

int main(){
    int n,k;
    cin>>n>>k;
    int dp[n+1][k+1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    dp[1][1] = 1;
    rep(i,2,n){
        rep(j,1,min(i,k)){
            rep(l,0,j)
                dp[i][j] += dp[i-j][l];
        }
    }
    long ans = 0;
    rep(i,1,k) ans+=dp[n][i];
    cout<<ans<<endl;
}