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
/*string smaller(string a, string b){
    if(a=="")
        return b;
    if(b=="")
        return a;
        int i = 0;
    while(a[i] == b[i])
        i++;
    if(a[i]<b[i])
        return a;
    else
        return b;
}*/
int main(){
    int t;
    scanf("%d",&t);
    rep(_,1,t){
        int n,m;
        scanf("%d%d",&n,&m);
        char s[n][m+1];
        f(i,0,n) scanf("%s",s[i]);
        vector<vector<string>> dp(n,vector<string>(m+1,""));
        repd(i,m-1,0){
            if(i!=m-1 && dp[n-1][i+1]=="")
                dp[n-1][i] = "";
            else{
                if(s[n-1][i]=='#')
                    dp[n-1][i] = "";
                else
                    dp[n-1][i] = s[n-1][i] + dp[n-1][i+1];
            }
        }
        repd(i,n-2,0){
            repd(j,m-1,0){
                if(s[i][j] == '#')
                    dp[i][j] = "";
                else{
                    string a = dp[i][j+1];
                    string b = dp[i+1][j];
                    string ans;
                    if(a=="") ans = b;
                    else if(b=="") ans = a;
                    else{
                        int idx = 0;
                        while(a[idx]==b[idx]) idx++;
                        if(idx == sz(a)) ans = a;
                        else if(a[idx]<b[idx]) ans = a;
                        else ans = b;
                    }
                    dp[i][j] = s[i][j] + ans;


                }
            }
        }
        cout<<dp[0][0]<<endl;

    }

}