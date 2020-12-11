//https://atcoder.jp/contests/dp/tasks/dp_b
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
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> h(n);
    f(i,0,n) cin>>h[i];
    vector<int> dp(n,INT_MAX);
    dp[0] = 0;
    f(i,1,n)
        rep(j,1,min(i,k))
            dp[i] = min(dp[i], dp[i-j] + abs(h[i]-h[i-j]));
    cout<<dp[n-1]<<endl;
}
//dp[i] = min(dp[i-j] + abs(h[i]-h[j])),j = 1 to min(i,k)
