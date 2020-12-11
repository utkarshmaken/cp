//https://atcoder.jp/contests/dp/tasks/dp_d
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
ll knapsack(int i, int w){
    if(i==n) return 0;
    if(dp[i][w]!=-1) return dp[i][w];
    ll a1 = 0,a2 = 0;
    if(wt[i]<=w)
        a1 = v[i] + knapsack(i+1,w-wt[i]);
    a2 = knapsack(i+1,w);
    return dp[i][w] = max(a1,a2);
}
int main(){
    cin>>n>>w;
    f(i,0,n) cin>>wt[i]>>v[i];
    memset(dp,-1,sizeof(dp));
    cout<<knapsack(0,w)<<endl;
}