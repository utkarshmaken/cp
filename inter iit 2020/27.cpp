//NUMBER OF SUBSTRINGS INA STRING
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
    string s,t;
    cin>>s>>t;
    int n = sz(s),m = sz(t);
    int lps[m];
    lps[0] = 0;int len = 0;
    int i = 1,j;
    while(i<m){
        if(t[len] == t[i]){
            ++len;
            lps[i] = len;
            ++i;
        }
        else{
            if(len!=0)
                len = lps[len-1];
            else{
                lps[i] = 0;
                ++i;
            }
        }
    }
    i = 0;j = 0;
    int ans  = 0;
    while(i<n){
        if(s[i] == t[j]){
            ++i;++j;
        }
        if(j==m){
            ++ans;
            j = lps[j-1];
        }
        else if(i<n && s[i]!=t[j]){
            if(j == 0) ++i;
            else j = lps[j-1];
        }
    }
    cout<<ans<<endl;


}