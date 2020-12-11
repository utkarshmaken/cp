//DICE THROW DP
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
const int maxn = 2e5;
int main(){
    int n,m,x;
    cin>>n>>m>>x;
    int dp[n+1][x+1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    rep(i,1,n){
        rep(j,1,x){
            dp[i][j] = dp[i-1][j-1] + dp[i][j-1] - (j-1>=m?dp[i-1][j-1-m]:0);
        }
    }
    cout<<dp[n][x]<<endl;
}