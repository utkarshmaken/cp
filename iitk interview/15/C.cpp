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
    int maxi = 1;
    vector<int> dp(n,1);
    f(i,1,n){
        repd(j,i-1,0)
            if(a[j]<a[i])
                dp[i] = max(dp[i],1+dp[j]);
        
        maxi = max(maxi,dp[i]);
    }
    int ans = n-maxi;
    if(ans==0)
        cout<<0<<endl;
    else
        cout<<ans-1<<endl;
    
}