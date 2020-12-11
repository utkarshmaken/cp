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
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        f(i,0,n) cin>>a[i];
        int dp[n][2][3];
        memset(dp,0,sizeof(dp));
        dp[0][0][1] = (a[0]==1);
        dp[0][0][2] = INT_MAX;
        dp[0][1][1] = dp[0][1][2] = INT_MAX;

        f(i,1,n){
            if(min(dp[i-1][1][1],dp[i-1][1][2])!=INT_MAX)
                dp[i][0][1] = (a[i]==1) + min(dp[i-1][1][1],dp[i-1][1][2]);
            else
                dp[i][0][1] = INT_MAX;
            if(i>1 && min(dp[i-2][1][1],dp[i-2][1][2]) != INT_MAX)
                dp[i][0][2] = (a[i]==1) + (a[i-1]==1) + min(dp[i-2][1][1],dp[i-2][1][2]);
            else
                dp[i][0][2] = (i==1?(a[i]==1) + (a[i-1]==1):INT_MAX);

            dp[i][1][1] = min(dp[i-1][0][1],dp[i-1][0][2]);
            
            if(i>1)
                dp[i][1][2] = min(dp[i-2][0][1],dp[i-2][0][2]);
            else
                dp[i][1][2] = INT_MAX;
            
            //cout<<dp[i][0][1]<<' '<<dp[i][0][2]<<' '<<dp[i][1][1]<<' '<<dp[i][1][2]<<endl;
        }
        int ans = INT_MAX;
        ans = min(dp[n-1][0][1],dp[n-1][0][2]);
        ans = min(ans,min(dp[n-1][1][1],dp[n-1][1][2]));
        cout<<ans<<endl;
    }

}