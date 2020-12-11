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

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    f(i,0,n) cin>>a[i];
    
    vector<int> dp(n+1,INT_MAX);
    dp[0] = INT_MIN;
    f(i,0,n){
        int j = upper_bound(all(dp),a[i]) - dp.begin();
        if(dp[j-1]<a[i] && a[i]<dp[j])
            dp[j] = a[i];
    }
    int maxi = 1;
    rep(i,1,n)
        if(dp[i]!=INT_MAX)
            maxi = i;
    
    int ans = n-maxi;
    if(ans==0)
        cout<<0<<endl;
    else
        cout<<ans-1<<endl;
    
}