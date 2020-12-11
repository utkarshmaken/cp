//Find the maximum possible sum of subsets of 
//given array formed by only non-adjacent elements.

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
    int n;cin>>n;
    vector<int> arr(n);
    f(i,0,n) cin>>arr[i];
    int dp[n][2];
    dp[0][0] = arr[0];
    dp[0][1] = 0;
    f(i,1,n){
        dp[i][0] = arr[i] + dp[i-1][1];
        dp[i][1] = max(dp[i-1][0],dp[i-1][1]);
    }
    int ans = max(dp[n-1][0],dp[n-1][1]);
    cout<<ans<<endl;
}
