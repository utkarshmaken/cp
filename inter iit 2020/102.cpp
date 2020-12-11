//Longest Ordered Subsequence of Vowels
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

int main(){
    string s;
    cin>>s;
    int n = sz(s);
    int dp[n][5];
    memset(dp,0,sizeof(dp));
    map<char,int> m;
    m['a'] = 0;m['e'] = 1;m['i'] = 2;m['o'] = 3;m['u'] = 4;
    dp[0][m[s[0]]] = 1;
    f(i,1,n){
        if(m.find(s[i]) == m.end()){
            f(j,0,5)
                dp[i][j] = dp[i-1][j];
        }
        else{
            if(s[i] == 'a')
                dp[i][0] = 1 + dp[i-1][0];
            f(j,1,5){
                if(j == m[s[i]])
                    dp[i][j] = max(dp[i-1][j], 1 + dp[i-1][j-1]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n-1][4]<<endl;

}