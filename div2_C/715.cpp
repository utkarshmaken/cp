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
    int n;
    cin >> n;
    vector<int> s(n);
    f(i,0,n) cin >> s[i];
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    sort(all(s));
    ll ans = 0;
    ll dp[n][n] = {0};
    f(i,0,n-1) dp[i][i+1] = s[i+1] - s[i];
    rep(k,3,n){
        for(int i = 0, j = i+k-1; j < n; i++,j++) {
            dp[i][j] = s[j] - s[i] + min(dp[i+1][j], dp[i][j-1]);
        }
    }
    cout << dp[0][n-1] << endl;
    
}