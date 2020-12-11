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
const int maxn = 100001;
string res;int m,len;
int pos[3000][26];
ll dp[3000][3000];
ll find(int i,int last){
    if(i==m) return 1;
    if(last==len) return 0;
    if(dp[i][last]!=-1) return dp[i][last];
    int c = res[i] - 'a';
    if(pos[last][c]==0)
        return dp[i][last] = find(i,last+1);
    else{
        ll ans =  (pos[last][c]*find(i+1,last+1))%mod;
        ans = (ans + find(i,last+1))%mod;
        return dp[i][last] = ans;
    }

}
int main(){
    int n;
    cin>>n;
    vector<string> s(n);
    f(i,0,n) cin>>s[i];
    cin>>res;
    len= sz(s[0]);
    memset(pos,0,sizeof(pos));
    memset(dp,-1,sizeof(dp));
    
    f(i,0,n)
        f(j,0,len)
            pos[j][s[i][j]-'a']++;

    m = res.size();
    ll ans = find(0,0);
    cout<<ans<<endl;

}