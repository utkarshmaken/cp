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
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        if(k == 1){
            cout << 1 << endl;
            continue;
        }
        if(n == 1){
            cout << 2 << endl;
            continue;
        }

        long dp[n+1][k+1] = {0};
        rep(i,1,k) dp[n][i] = 1;
        rep(i,1,n) dp[i][1] = 1;
        rep(j,2,k){
            repd(i,n-1,0){
               dp[i][j] = (dp[i+1][j] + dp[n-i][j-1]) % mod;
            }
        }
        cout << dp[0][k] << endl;
    }

}


/*T(x,k) = T(x+1,k) + T(n-x,k-1);

T(x,1) = 1
T(n,k) = 1*/

