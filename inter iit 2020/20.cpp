//SPORTS DAY
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for(int i = 0;i<n;i++) cin>>grid[i];
    int dp[n+1][m+1][2];
    memset(dp,0,sizeof(dp));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j]=='x') continue;
            dp[i+1][j+1][0] = 1+dp[i+1][j][0];
            dp[i+1][j+1][1] = 1+dp[i][j+1][1];
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            int ht = dp[i][j][1];
            if(ht<=1) continue;
            int j_min = j-dp[i][j][0]+1;
            for(int j0 = j-1;j0>=j_min;j0--){
                int ht1 = dp[i][j0][1];
                if(ht1<=1) continue;
                int h = min(ht,ht1);
                int i0 = i - h + 1;
                while(j-dp[i0][j][0]+1 > j0 && i0<i) ++i0;
                if(i0 == i) continue;
                ans = max(ans,2*(j-j0) + 2*(i-i0) );
            }
        }
    }
    cout<<ans<<endl;
}