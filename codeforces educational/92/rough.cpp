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
using namespace std;
const int mod = 1000000007;
const int maxn = 200000;
int n,k,z;
vector<int> a(maxn);
ll dp[maxn][6];
 int solve(int i, int k, int z){
    if(k==0)
        return a[i];
    if(dp[i][z]!=-1)
        return dp[i][z];
    int right = INT_MIN,left = INT_MIN;
    if(i!=n-1)
        right = solve(i+1,k-1,z);
    if(i!=0 && z>0)
        left = solve(i-1,k-1,z-1);

    return dp[i][z] = a[i] + max(left,right);

}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k>>z;
        f(i,0,n) cin>>a[i];
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,k,z)<<endl;
    }

}