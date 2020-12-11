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
int main(){
    int t,n,k,l;
    vector<int> d(maxn+1);
    cin>>t;
    while(t--){
        cin>>n>>k>>l;
        rep(i,1,n) cin>>d[i];
        vector<int> p;
        rep(i,0,k) p.pb(i);
        repd(i,k-1,1) p.pb(i);
        bool dp[n+1][2*k] = {false};
        f(i,0,2*k) dp[0][i] = true;
        rep(i,1,n){
            f(t,0,2*k){
                if(dp[i-1][(t-1 + 2*k)%(2*k)]  || dp[i][(t-1 + 2*k)%(2*k)])
                    if(d[i] + p[t]<=l)
                        dp[i][t] = true;
                else 
                   dp[i][t] = false;
            }
        }
        bool flag = false;
        f(i,0,2*k)
            if(dp[n][i])
                flag = true;

        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;        
    }

}