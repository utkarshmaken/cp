//K-SUBSEQUENCES
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
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    f(i,0,n) cin>>nums[i];
    long ans = 0;
    f(i,0,n) nums[i] = nums[i]%k;
    int dp[n][k];
    memset(dp,0,sizeof(dp));
    dp[0][nums[0]] = 1;
    f(i,1,n){
        f(j,0,k) dp[i][(j+nums[i])%k]+=dp[i-1][j];
        dp[i][nums[i]]++;
    }
    f(i,0,n) ans+=dp[i][0];
    cout<<ans<<endl;

}