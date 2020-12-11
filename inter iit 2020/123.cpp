#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    vector<int> dp(60);
    dp[1] = 1;
    int x = 2;
    for(int i = 2; i < 60; i++){
        int sum = 0;
        for(int j = 1; j <= i; j++)
            sum += x++;
        dp[i] = sum;
    }
    while(t--){
        int n;
        cin>>n;
        ++n;
        cout<<dp[n]<<endl;
    }

}