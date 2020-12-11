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
int main(){
    int n;cin>>n;
    int grid[n][n];
    f(i,0,n) f(j,0,n) cin>>grid[i][j];
    if(grid[n-1][n-1]==-1 || grid[0][0]==-1){
        cout<<0<<endl;
        return 0;
    }

    vector<vector<int>> dp_prev(n+1,vector<int>(n+1,INT_MIN));
    vector<vector<int>> dp_curr(n+1,vector<int>(n+1,INT_MIN));
    dp_prev[n-1][n-1] = (grid[n-1][n-1]==1);
    repd(t,2*n-3,0){
        repd(i1,min(n-1,t),max(0,t-n+1)){
            repd(i2,min(n-1,t),max(0,t-n+1)){
                int j1 = t-i1,j2 = t-i2;
                if(grid[i1][j1]==-1 || grid[i2][j2]==-1){
                    dp_curr[i1][i2] = INT_MIN;
                    continue;
                }
                int ans = 0;
                if(i1==i2) ans+=grid[i1][j1];
                else ans+=grid[i1][j1] + grid[i2][j2];

                int a1 = max(dp_prev[i1+1][i2],dp_prev[i1][i2]);
                int a2 = max(dp_prev[i1+1][i2+1],dp_prev[i1][i2+1]);
                
                if(a1==INT_MIN && a2==INT_MIN)
                    dp_curr[i1][i2] = INT_MIN;
                else
                    dp_curr[i1][i2] = ans+max(a1,a2);

            }
        }
        dp_prev = dp_curr;
    }
    cout<<max(0,dp_prev[0][0])<<endl;
  
}