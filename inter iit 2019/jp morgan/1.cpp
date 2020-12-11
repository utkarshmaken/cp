//MINIMUM POSSIBLE SIZE ARRAY
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
const int maxn = 1e5;
int dp[100][100];
int find(vector<int> &arr, int i, int n, int k){
    if(i == n) return 1;
    if(i>n) return 0;
    if(dp[i][n]!=-1) return dp[i][n];

    int ans = 1 + find(arr,i+1,n,k);
    for(int idx = i+1;idx < n;idx++){
        if(arr[idx]-arr[i]==k && find(arr,i+1,idx-1,k) == 0){
            for(int idx2 = idx+1;idx2<=n;idx2++){
                if(arr[idx2]-arr[idx]==k && find(arr,idx+1,idx2-1,k) == 0){
                    ans = min(ans, find(arr,idx2+1,n,k));
                }
            }
        }
    }
    return dp[i][n] = ans;
}
int main(){
    int n;cin>>n;
    vector<int> arr(n);
    f(i,0,n) cin>>arr[i];
    int k;cin>>k;
    memset(dp,-1,sizeof(dp));
    int ans = find(arr,0,n-1,k);
    cout<<ans<<endl;
}