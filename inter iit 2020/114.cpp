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
    int rep;
    cin>>rep;
    while(rep--){
        string t,s;
        cin>>t;
        cin>>s;
        int n = sz(s), m = sz(t);
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        rep(i,0,m) dp[0][i] = i;
        rep(i,0,n) dp[i][0] = i;
        rep(i,1,n){
            rep(j,1,m){
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
        }
        cout<<dp[n][m]<<endl;
    }
}