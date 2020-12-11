//GROUPING OPTIONS
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
    int n,k;
    cin>>n>>k;
    n-=k;
    ll dp[n+1][k+1];
    memset(dp,0ll,sizeof(dp));
    dp[0][0] = 1;
    rep(i,1,k) dp[0][i] = 1;
    rep(i,1,n){
        rep(j,1,k){
            if(i<j) dp[i][j] = dp[i][j-1]; 
            else dp[i][j] = dp[i][j-1] + dp[i-j][j];
        }
    }
    cout<<dp[n][k]<<endl;

}