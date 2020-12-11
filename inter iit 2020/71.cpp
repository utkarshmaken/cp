//NO OF UNIQUE SUBSEQUENCES OF A STRING
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
const int maxn = 1e5;

int main(){
    string s;
    cin>>s;
    int n = sz(s);
    int dp[n+1],sum[n+1],last[26];
    memset(dp,0,sizeof(dp));
    memset(sum,0,sizeof(sum));
    memset(last,0,sizeof(last));
    dp[0] = 1;sum[0] = 1;
    rep(i,1,n){
        dp[i] = sum[i-1] - (last[s[i-1]-'a']>0?sum[last[s[i-1] - 'a'] - 1]:0);
        sum[i] = dp[i] + sum[i-1];
        last [s[i-1]-'a'] = i;
    }
    cout<<sum[n]<<endl;

}