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
    int m;
    cin>>m;
    vector<int> p(m);
    f(i,0,m) cin>>p[i];
    int n;cin>>n;
    sort(all(p));
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,INT_MAX));
    rep(i,0,m) dp[0][i] = 0;
    rep(i,1,n){
        rep(j,1,m){
           dp[i][j] = dp[i][j-1];
           if(p[j-1] <= i)  dp[i][j] = min(dp[i][j],1+dp[i-p[j-1]][j]);
        }
    }
    cout<<(dp[n][m]==INT_MAX?-1:dp[n][m])<<endl;
    
    
}
