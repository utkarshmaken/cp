//MAXIMUM SIZE OF SUBMATRIX WITH ALL SUBMATRICES WITH SUM
//LESS THAN K
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
const int maxn = 2e5;
int sum[1000][1000];
int n,m;
bool poss(int len, int k){
    f(i,0,n){
        f(j,0,m){
            if(i+len-1 >=n || j+len-1>=m) continue;
            int s = sum[i+len][j+len] - sum[i+len][j] - sum[i][j+len] + sum[i][j];
            if(s > k) return false;
        }
    }
    return true;
}
int main(){
    cin>>n>>m;
    int grid[n][m];
    f(i,0,n)
        f(j,0,m)
            cin>>grid[i][j];
    int k;cin>>k; 
    memset(sum,0,sizeof(sum));
    rep(i,1,n)
        rep(j,1,m)
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + grid[i-1][j-1];
    
    int low = 1,high = min(n,m);
    if(!poss(1,k)){
        cout<<0<<endl;
        return 0;
    }
    int ans = 1;
    while(low<=high){
        int mid = (low+high)/2;
        if(poss(mid,k)){
            ans = mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }
    cout<<ans<<endl;
}