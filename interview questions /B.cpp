//https://leetcode.com/discuss/interview-question/584289/
#include <bits/stdc++.h>
using namespace std;

int arr[111][111],dp[111][111][111];
int m,n;

int find(int i1, int j1, int j2){
    if(i1>=m || j1<0 || j1>=n || j2<0 || j2>=n) return INT_MIN;
    if(i1==m-1 && j1==0 && j2==n-1) return arr[m-1][0] + arr[m-1][n-1];
    if(dp[i1][j1][j2]!=-1) return dp[i1][j1][j2];

    int ans = 0;
    if(j1==j2)
        ans=arr[i1][j1];
    else
        ans=arr[i1][j1] + arr[i1][j2];
    
    int a1 = max(find(i1+1,j1-1,j2),max(find(i1+1,j1,j2),find(i1+1,j1+1,j2)));
    int a2 = max(find(i1+1,j1-1,j2-1),max(find(i1+1,j1,j2-1),find(i1+1,j1+1,j2-1)));
    int a3 = max(find(i1+1,j1-1,j2+1),max(find(i1+1,j1,j2+1),find(i1+1,j1+1,j2+1)));
    ans+=max(a1,max(a2,a3));
    dp[i1][j1][j2] = ans;
    return ans;
}
int main(){
    cin>>m>>n;
    if(m==0 || n==0){
        cout<<-1<<endl;
        return 0;
    }
    
    for(int i = 0;i<m;i++)
        for(int j = 0;j<n;j++)
            cin>>arr[i][j];
    
    if(n==1){
        cout<<-1<<endl;
        return 0;
    }

    for(int i = 0;i<m;i++)
        for(int j = 0;j<m;j++)
            for(int k = 0;k<m;k++)
                dp[i][j][k] = -1;

    cout<<find(0,0,n-1);
   
}