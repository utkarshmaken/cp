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
const int maxn = 100001;
vector<ll> red(maxn),green(maxn),blue(maxn);
int r,g,b;
ll dp[201][201][201];
ll solve(int i, int j, int k){
    if(i>=r && j>=g && k>=b) return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    ll a1 = 0,a2 = 0,a3 = 0;
    if(i<r && j<g) a1 = red[i]*green[j] + solve(i+1,j+1,k);
    if(i<r && k<b) a2 = red[i]*blue[k] + solve(i+1,j,k+1);
    if(j<g && k<b) a3 = green[j]*blue[k] + solve(i,j+1,k+1);
    dp[i][j][k] = max(a1,max(a2,a3));
    return dp[i][j][k];
}
int main(){
    cin>>r>>g>>b;
    f(i,0,r) cin>>red[i];
    f(i,0,g) cin>>green[i];
    f(i,0,b) cin>>blue[i];
    sort(all(red));sort(all(green));sort(all(blue));
    reverse(all(red));reverse(all(green));reverse(all(blue));
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0,0)<<endl;
}