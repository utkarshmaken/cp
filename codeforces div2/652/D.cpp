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
#define mp make_pair
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
using namespace std;
const int mod = 1000000007;
const int maxn = 2*pow(10,6);
int main(){
    vector<ll> dp(maxn+1);
    dp[1] = 0;
    dp[2] = 0;
    rep(i,3,maxn)
        dp[i] = (dp[i-1] + 2ll*dp[i-2] + (i%3==0?4:0))%mod;
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        cin>>n;
        cout<<dp[n]%mod<<endl;
    }
}