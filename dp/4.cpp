//https://atcoder.jp/contests/dp/tasks/dp_a
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
    int n;
    scanf("%d", &n);
    vector<int> h(n);
    f(i,0,n) cin>>h[i];
    vector<int> dp(n);
    dp[0] = 0;dp[1] = abs(h[1]-h[0]);
    f(i,2,n)
        dp[i] = min(dp[i-2] + abs(h[i]-h[i-2]),dp[i-1] + abs(h[i]-h[i-1]));
    cout<<dp[n-1]<<endl;
}

