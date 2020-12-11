//QUERIES AND OPERATIONS
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
#define mp make_pair
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
#define endl '\n'
using namespace std;
const int mod = 1000000007;
const int maxn = 1e6;

int main(){
    int n;
    cin>>n;
    vector<ll> arr(n+1);
    rep(i,1,n) cin>>arr[i];
    int m = sqrt(n);
    ll pre_sum[n+1][m+1];
    ll pre_pro[n+1][m+1];
    repd(i,n,1){
        rep(j,1,m){
            pre_sum[i][j] = (arr[i] + (i+j>n?0:pre_sum[i+j][j]))%mod;
            pre_pro[i][j] = (arr[i]*(i+j>n?1:pre_pro[i+j][j]))%mod;
        }
    }
    int q;
    cin>>q;
    f(i,0,q){
        int t,x,y;
        cin>>t>>x>>y;
        if(y>m){
            ll ans = 0;
            if(t == 0){
                for(int j = x;j<=n;j+=y)
                    ans= (ans + arr[j])%mod;
            }
            else{
                for(int j = x;j<=n;j+=y)
                    ans = (ans*arr[j])%mod;
            }
            cout<<ans<<endl;

        }
        else{
            ll ans = 0;
            if(t == 0)
                ans = pre_sum[x][y];
            else
                ans = pre_pro[x][y];
            cout<<ans<<endl;
        }
    }

}