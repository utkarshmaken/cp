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
long dp[maxn+1][10][11];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,sizeof(dp),0);

    rep(i,0,9)
        dp[0][i][i] = 1;
        
    rep(i,1,maxn){
        rep(j,0,9){
            long temp = dp[i-1][j][9] % mod;
            long sum = 0;
            repd(k,9,1){
                dp[i][j][k] = dp[i-1][j][k-1];
                sum = (sum + dp[i][j][k]) % mod;
            }
            dp[i][j][1] = (dp[i][j][1] + temp) % mod;
            dp[i][j][0] = temp;
            sum = (sum + (2ll*temp)%mod) % mod;
            dp[i][j][10] = sum;
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        long ans = 0;
        while(n){
            int dig = n % 10;
            n /= 10;
            ans = (ans + dp[m][dig][10]) % mod;
        }

        cout << ans << endl; 
    }

}