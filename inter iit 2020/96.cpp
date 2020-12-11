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
const ll mod = 1000000007;
const int maxn = 1e5;
ll dp[1000][2500];
string s;
int n,x,y,len;
int main(){
    cin>>s;
    cin>>n>>x>>y;
    len = sz(s);
    memset(dp,0,sizeof(dp));
    vector<int> prev(len);
    int idxl = -1, idxr = -1;
    f(i,0,len){
        if(s[i] == 'l'){
            prev[i] = idxl;
            idxl = i;
        }
        else{
            prev[i] = idxr;
            idxr = i;
        }
    }
    dp[0][x] = 1;
    rep(i,1,len){
        rep(j,0,n){
            dp[i][j] = dp[i-1][j];
            if(s[i-1] == 'l' && j+1<=n){
                dp[i][j] = (dp[i][j] + dp[i-1][j+1])%mod;
                if(prev[i-1] != -1)
                    dp[i][j] = (dp[i][j] - dp[prev[i-1]][j+1] + mod)%mod;
            }
            else if(s[i-1] == 'r' && j-1>=0){
                dp[i][j] = (dp[i][j] + dp[i-1][j-1])%mod;
                if(prev[i-1] != -1)
                    dp[i][j] = (dp[i][j] - dp[prev[i-1]][j-1] + mod)%mod;
            }
        }
    }
    cout<<dp[len][y]<<endl;

}