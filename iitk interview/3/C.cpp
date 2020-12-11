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
bool compare(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> time(n,vector<int>(3));
    f(i,0,n) cin>>time[i][0];
    cin>>n;
    f(i,0,n){
        cin>>time[i][1];
        time[i][1]+=time[i][0];
    }
    cin>>n;
    f(i,0,n) cin>>time[i][2];
    sort(all(time),compare);
    vector<int> end(n);
    f(i,0,n) end[i] = time[i][1];
    vector<int> dp(n);
    dp[0] = time[0][2];
    rep(i,1,n-1){
        dp[i] = dp[i-1];
        int start = time[i][0];
        auto it = upper_bound(all(end),start);
        if(it==end.begin())
            dp[i] = max(dp[i], time[i][2]);
        else
            dp[i] = max(dp[i], dp[it-end.begin()-1]+time[i][2]);
    }
    cout<<dp[n-1]<<endl;
}