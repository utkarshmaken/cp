//https://atcoder.jp/contests/dp/tasks/dp_c
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
    int n;
    cin>>n;
    vector<int> a(n),b(n),c(n);
    f(i,0,n) cin>>a[i]>>b[i]>>c[i];
    vector<vector<ll>> dp(n,vector<ll>(3,0));
    dp[0][0] = a[0];dp[0][1] = b[0];dp[0][2] = c[0];
    f(i,1,n){
        dp[i][0] = a[i] + max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = c[i] + max(dp[i-1][0],dp[i-1][1]);
    }    
    cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<endl;

}