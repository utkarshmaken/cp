//https://atcoder.jp/contests/dp/tasks/dp_e
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
int n,w;
vector<int> wt(101),v(101);
ll dp[101][100001];
ll knapsack(int w){
    vector<int>s,s1;
    dp[0][0] = 0;dp[0][v[0]] = wt[0];
    s.pb(0);s.pb(v[0]);
    f(i,1,n){
        s1.clear();
        for(auto x:s){
            dp[i][x+v[i]] = min(dp[i][x+v[i]],dp[i-1][x] + wt[i]);
            dp[i][x] = min(dp[i][x],dp[i-1][x]);
            s1.pb(x+v[i]);s1.pb(x);
        }
        s = s1;
    }
    ll ans = 0;
    f(i,0,100001)
        if(dp[n-1][i]<=w) ans = i;
    return ans;

}
int main(){
    cin>>n>>w;
    f(i,0,n) cin>>wt[i]>>v[i];
    f(i,0,101) f(j,0,100001) dp[i][j] = INT_MAX;
    cout<<knapsack(w)<<endl;
}