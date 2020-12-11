//SPY AGENCY
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
int lcs(string &s1, string &s2, int &n1, int &n2){
    int dp[n1+1][n2+1];
    memset(dp,0,sizeof(dp));
    f(i,0,n1){
        f(j,0,n2){
            if(s1[i]==s2[j])
                dp[i+1][j+1] = 1+dp[i][j];
            else
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
        }
    }
    return dp[n1][n2];

}
int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    int x,y;
    cin>>x>>y;
    int n1 = s1.size(),n2 = s2.size();
    int len = lcs(s1,s2,n1,n2);
    int ans = (min(n1,n2) - len)*y + (max(n1,n2) - min(n1,n2))*x;
    cout<<ans<<endl;


}