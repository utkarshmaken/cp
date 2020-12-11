
//https://codeforces.com/problemset/problem/1061/C
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

vector<int> factors(int x){
    vector<int> f1,f2;
    int rootx = pow(x,0.5);
    rep(i,1,rootx){
        if(x%i==0){
            f1.pb(i);
            if(i*i!=x)
                f2.pb(x/i);
        }
    }
    reverse(all(f1));
    f2.insert(f2.end(),all(f1));
    return f2;

}
int main(){
    
    int n;
    cin>>n;
    vector<ll> dp(n+1);
    dp[0] = 1;
    int x;
    rep(i,1,n){
        cin>>x;
        vector<int> f = factors(x);
        for(auto x:f){
            if(x<=i)
                dp[x] = (dp[x]+dp[x-1])%mod;;
        }
    }
    int ans = 0;
    rep(i,1,n)
        ans= (ans+dp[i])%mod;
    cout<<ans<<endl;
}