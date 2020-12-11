#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll m,n;
    cin>>n>>m;
    vector<ll> a(n),h(n);
    for(int i = 0;i<n;i++) cin>>a[i];
    for(int i = 0;i<n;i++) cin>>h[i];
    vector<vector<ll>> arr(n+1,vector<ll>(n));
    for(int i = 1;i<=n;i++)
        for(int j = 0;j<n;j++)
            arr[i][j] = a[j] + (i-1)*h[j];
    int ans;
    ll sum = 0;
    for(int i = n;i>=1;i--){
        sort(arr[i].begin(),arr[i].end());
        sum = 0;
        ans = i;
        for(int j = 0;j<i;j++) sum+=arr[i][j];
        if(sum <= m) break;
    }
    cout<<ans<<endl;
    cout<<sum<<endl;
    
}