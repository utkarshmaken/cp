//BINARY NUMBERS WITHOUT 11
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
    int t;
    cin>>t;
    vector<ll> dp(50);
    dp[1] = 1;dp[2] = 2;
    rep(i,3,49){
        dp[i] = 1+dp[i-1]+dp[i-2];
    }    
    while(t--){
        ll k;
        cin>>k;
        string ans = "";
        int f = 0;
        repd(i,49,0){
            if(k<=dp[i]){
                if(f==1) ans+='0';
                continue;
            }
            f = 1;
            ans+='1';
            k-=(dp[i]+1);
        }

        cout<<ans<<endl;
    }
}