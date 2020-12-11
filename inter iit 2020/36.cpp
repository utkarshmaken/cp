//LONGEST VALID PARENTHESIS
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
    string s;
    cin>>s;
    int n = s.size();
   
    vector<int> dp(n,0);
    dp[0] =0;
    for(int i = 1;i<n;i++){
        if(s[i] == ']'){
            if(s[i-1] == '[')
                dp[i] = 1 + (i-2>=0?dp[i-2]:0);
            else{
                if(i-1-dp[i-1] >=0 && s[i-1-dp[i-1]] == '[')
                    dp[i] = 2*dp[i-1] + (i-2-dp[i-1]>=0?dp[i-2-dp[i-1]]:0);
            }
        }
    }
    int trp = 0;
    f(i,0,n) trp = max(trp,dp[i]);
    cout<<trp<<endl;
}