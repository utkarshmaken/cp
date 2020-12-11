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
    int t;
    cin>>t;
    while(t--){
        int n,m,tc;
        cin>>n>>m>>tc;
        int dp[n][tc+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i = 1;i<=m;i++) dp[0][0][i] = 1;
        for(int i = 1;i<n;i++){
            for(int t = 0;t<=tc;++t){
                for(int last = 1;last<=m;++last){
                    dp[i][t][last] +=  dp[i-1][t][last]*(last);
                    for(int j = last+1;j<=m;j++)
                        dp[i][t+1][j]+=dp[i-1][t][last];
                }
            }
        }
        int ans = 0;
        for(int j = 1;j<=m;++j)
                ans+=dp[n-1][tc][j];
        cout<<ans<<endl;
    }
}
