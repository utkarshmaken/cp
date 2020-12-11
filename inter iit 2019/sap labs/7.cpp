//UMBRELLA
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
    int p;cin>>p;
    vector<int> arr(p);
    f(i,0,p) cin>>arr[i];
    sort(all(arr));
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    dp[arr[0]] = 1;
    rep(i,arr[0]+1,n){
        auto it = upper_bound(all(arr),i);
        --it;
        int idx = it-arr.begin();
        int ans = INT_MAX;
        rep(j,0,idx){
            if(dp[i-arr[j]]!=-1)
                ans = min(ans,1+dp[i-arr[j]]);
        }
        if(ans!=INT_MAX) dp[i] = ans;
    }
    cout<<dp[n]<<endl;

}