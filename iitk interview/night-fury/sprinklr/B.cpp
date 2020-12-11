//MIN MATRIX JUMPS
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
int n,m;
int dp[1000][1000];
int find(vector<vector<int>> &grid, int i, int j){
    if(i==n-1 && j==m-1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int newi = i+grid[i][j],newj = j+grid[i][j];
    int a1 = INT_MAX,a2 = INT_MAX;
    if(newi<n) a1 = find(grid,newi,j);
    if(newj<m) a2 = find(grid,i,newj);
    a1+=(a1==INT_MAX?0:1);
    a2+=(a2==INT_MAX?0:1);
    return dp[i][j] = min(a1,a2);
}
int main(){
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    f(i,0,n) f(j,0,m) cin>>grid[i][j];
    memset(dp,-1,sizeof(dp));
    int ans = find(grid,0,0);
    cout<<(ans==INT_MAX?-1:ans);
}