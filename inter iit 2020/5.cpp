//COIN CHANGE WITH ORDERING
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
    int  n;cin>>n;
    vector<int> dp(n+1);
    dp[2] = 1;dp[3] = 1;dp[4] = 2;dp[5] = 3;
    for(int i = 6;i<=n;i++)
        dp[i] = dp[i-2] + dp[i-3] + dp[i-5];
    cout<<dp[n]<<endl;  
}