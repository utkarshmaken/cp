#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        ll dp[n+1][k+1];
        memset(dp,0,sizeof(dp));
        dp[1][0] = 1;
        dp[2][0] = 2;
        dp[3][0] = 3;dp[3][1] = 1;
        for(int i=4;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(j==0)
                {
                    dp[i][j] = (dp[i-1][j] + dp[i-2][j])%mod;
                }
                else
                {
                    dp[i][j] = (dp[i-1][j]+dp[i-2][j]+ dp[i-3][j-1])%mod;
                }
            }
        }
        int res = 0;
        for(int i=0;i<=k;i++) res = (res + dp[n][i])%mod;
        cout<<res<<endl;
    }
}