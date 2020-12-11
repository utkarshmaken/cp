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
    int n;cin>>n;
    vector<ll> leaves(n);
    f(i,0,n) cin>>leaves[i];
    int m;cin>>m;

    int q;cin>>q;
    vector<ll> day(q);
    f(i,0,q) cin>>day[i];
    cin>>q;
    vector<pii> query(q);
    f(i,0,q) cin>>query[i].fi;
    cin>>q;
    f(i,0,q) cin>>query[i].se;

    ll dp[130][n+1];
    memset(dp,0ll,sizeof(dp));
    rep(i,1,n) dp[0][i] = leaves[i-1];
    f(i,0,n){
        rep(j,1,120){
            leaves[i]-=m*leaves[i]/100 + (m*leaves[i]%100>0?1:0);
            dp[j][i+1] = leaves[i];
        }
    }
    repd(j,120,1){
        rep(i,1,n)
            dp[j][i] = dp[j-1][i] - dp[j][i];
    }
    rep(j,1,120){
        rep(i,1,n)
            dp[j][i]+=dp[j][i-1];
    }
      

    f(i,0,q){
        int l = query[i].fi,r = query[i].se,j = day[i];
        if(j > 130) cout<<0<<endl;
        else cout<<dp[j][r] - dp[j][l-1]<<endl;
    }









}