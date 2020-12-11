//GOOD SUBSEQUENCES
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
ll dp[5000][10];
int n,len; string s;
vector<int> num(10);
long find( vector<int> digits[], int j, int prev){
    if(j==n) return 1;

    int d = num[j];
    auto it =  upper_bound(all(digits[d]),prev);
    long res = 0;
    while(it!=digits[d].end()){
        long ans;
        if(dp[*it][j] == -1);
            dp[*it][j] = find(digits,j+1,*it)%mod;
        res = (res + dp[*it][j])%mod;
        ++it;
    }
    return res;
}
int main(){
    cin>>s;
    cin>>n;
    f(i,0,n) cin>>num[i];
    len = sz(s);
    vector<int> digits[10];
    f(i,0,len){
        int d = s[i] - '0';
        digits[d].pb(i);
    }
    memset(dp,-1,sizeof(dp));
    long ans = find(digits,0,-1);
    cout<<ans<<endl;

}