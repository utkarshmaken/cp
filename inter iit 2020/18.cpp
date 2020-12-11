//OPERATIONAL ARRAY
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> arr(n,0);
    int q;cin>>q;
    for(int i = 0;i<q;i++){
        int type;cin>>type;
        if(type == 1){
            int l,r,x;
            cin>>l>>r>>x;
            arr[l]+=x;
            if(r+1<n) arr[r+1]-=x;
        }
        if(type==2){
            int i,x;
            cin>>i>>x;
            arr[i]+=x;
            if(i+1<n) arr[i+1]-=x;
        }
    }
    for(int i = 1;i<n;i++) arr[i]+=arr[i-1];
    vector<int> dp(n+1,INT_MAX);
    dp[0] = INT_MIN;
    for(int i = 0;i<n;i++){
        int x = arr[i];
        int idx = lower_bound(dp.begin(),dp.end(),x) - dp.begin();
        if(dp[idx]<=x && x<dp[idx+1])
            dp[idx+1] = x;
    }
    int ans = 0;
    for(int i = 1;i<=n;i++)
        if(dp[i]!=INT_MAX)
            ans = i;
    cout<<ans<<endl;

}