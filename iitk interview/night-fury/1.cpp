//ALMOST SORTED
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
    int n;cin>>n;
    vector<int> a(n);
    f(i,0,n) cin>>a[i];
    vector<int> dp(n+1,INT_MAX);
    dp[0] = INT_MIN;
    f(i,0,n){
        int x = a[i];
        int idx = upper_bound(all(dp),x) - dp.begin();
        if(dp[idx-1]<=x && dp[idx]>x)
            dp[idx] = x;
    }
    int len = 0;
    rep(i,1,n) if(dp[i]!=INT_MAX) len = i;
    if(len>=n-1) cout<<0<<endl;
    else cout<< n-len-1<<endl;

}