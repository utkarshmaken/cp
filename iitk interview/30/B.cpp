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
    int n,m;
    cin>>n>>m;
    int grid[n][m];
    f(i,0,n) f(j,0,m) scanf("%d",&grid[i][j]);
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    if(grid[n-1][m-1]==1) dp[n][m-1] = 1;
    repd(i,n-1,0)
        repd(j,m-1,0)
            if(grid[i][j]!=0)
                dp[i][j] = (dp[i][j+1] + dp[i+1][j])%mod;
    cout<<dp[0][0]<<endl;
}