//https://leetcode.com/discuss/interview-question/549128/
#include <bits/stdc++.h>
using namespace std;
int dp[10][10][10][10][6];
int total[11][11];
int berries(int i1, int j1, int i2, int j2){
    return total[i2+1][j2+1] + total[i1][j1] - total[i1][j2+1] - total[i2+1][j1];
}
int find(int i1, int j1, int i2, int j2, int k){
    if(k==1){
        if(berries(i1,j1,i2,j2)>0) return 1;
        else return 0;
    }
    if(i1==i2 && j1==j2){
        return 0;
    }
        
    if(dp[i1][j1][i2][j2][k]!=-1) return dp[i1][j1][i2][j2][k];
    int ans = 0;
    //vertical cut
        for(int j = j1;j<=j2-1;j++){
            if(berries(i1,j1,i2,j) > 0){
                ans+=find(i1,j+1,i2,j2,k-1);
            }
        }
    //horizontal cut
        for(int i = i1;i<=i2-1;i++){
            if(berries(i1,j1,i,j2)>0){
                ans+=find(i+1,j1,i2,j2,k-1);
            }
        }
        
    dp[i1][j1][i2][j2][k] = ans;
    return ans;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<string> cake(n);
        for(int i = 0;i<n;i++) cin>>cake[i];
        memset(total,0,sizeof(total));
        memset(dp,-1,sizeof(dp));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++)
                total[i][j] = (cake[i-1][j-1]=='v') + total[i][j-1] + total[i-1][j] -total[i-1][j-1];
        }
        cout<<find(0,0,n-1,m-1,k)<<endl;
    }
}