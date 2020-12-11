//BEST MEETING POINT

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
int solve1D(vector<int> &arr){
    int n = arr.size();
    int idx = n/2;
    int dist = 0;
    f(i,0,n) dist+=abs(arr[i]-arr[idx]);
    return dist;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    f(i,0,n) f(j,0,m) cin>>grid[i][j];
    vector<int> rows,cols;
    f(i,0,n)
        f(j,0,m)
            if(grid[i][j] == 1){
                rows.push_back(i);
                cols.push_back(j);
            }
    sort(all(rows));sort(all(cols));
    int ans = 0;
    ans+=solve1D(rows);
    ans+=solve1D(cols);
    cout<<ans<<endl;  
}