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
const int maxn = 10000000;
string s;
int dp[maxn+1];
vector<int> close;
int main(){
    int ti;
    scanf("%d",&ti);
    rep(_,1,ti){
        cin>>s;
        int n = sz(s);
        dp[n] = -1;
        repd(i,n-1,0){
            if(s[i]==')'){
                dp[i] = dp[i+1];
                close.pb(i);
            }
            else{
                if(!close.empty()){
                    dp[i] = close.back();
                    close.pop_back();
                }
                else
                {
                    dp[i] = -1;
                }
                
            }
        }
        int q;
        scanf("%d",&q);
        rep(__,1,q){
            int t;
            scanf("%d",&t);
            t--;
            if(dp[t]==-1)
                printf("%d\n",-1);
            else
                printf("%d\n",dp[t]+1);   
        }
        close.clear();
    }

}