//Find length of longest subsequence of one string 
//which is substring of another string
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
const ll mod = 1000000007;
const int maxn = 1e5;

int main(){
    string x,y;
    cin>>x>>y;
    int n = sz(x),m = sz(y);
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    rep(i,1,m){
        rep(j,1,n){
            if(y[i-1] == x[j-1])
                dp[j][i] = 1 + dp[j-1][i-1];
            else
                dp[j][i] = dp[j-1][i];
        }
    }
    int ans = 0;
    rep(i,1,m) ans = max(ans,dp[n][i]);
    cout<<ans<<endl;
    

}