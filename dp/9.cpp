//https://atcoder.jp/contests/dp/tasks/dp_f
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
    string s,t;
    cin>>s>>t;
    int n = sz(s),m = sz(t);
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    f(i,0,n){
        f(j,0,m){
            if(s[i]==t[j])
                dp[i+1][j+1] = 1 + dp[i][j];
            else
                dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
        }
    }
    int len = dp[n][m];
    string ans(len,'?');
    int i = n,j = m;
    while(len>0){
        if(s[i-1]==t[j-1]){
            ans[len-1] = s[i-1];
            len--;i--;j--;
        }
        else{
            if(dp[i][j-1]==len)
                j--;
            else
                i--;
        }
    }
    cout<<ans<<endl;
    
}