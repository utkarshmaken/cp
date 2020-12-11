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
bool flag = true;int n;
vector<string> grid1(100),grid2(100);
vector<pii> dir = {{-1,0},{0,-1},{0,1},{1,0}};

void dfs(int i, int j, vector<vector<bool>> &visited){
    visited[i][j] = true;
    if(grid1[i][j]=='0') flag = false;
    for(auto &p:dir){
        int newi = i+p.fi,newj = j+p.se;
        if(newi<0 || newj<0 || newi>=n || newj>=n || grid2[newi][newj]!='1' || visited[newi][newj])
            continue;
        dfs(newi,newj,visited);
    }
}
int main(){
    cin>>n;
    f(i,0,n) cin>>grid1[i];
    cin>>n;
    f(i,0,n) cin>>grid2[i];
    vector<vector<bool>> visited(n,vector<bool>(n));
    int ans = 0;
    f(i,0,n)
        f(j,0,n)
            if(!visited[i][j] && grid2[i][j]=='1'){
                dfs(i,j,visited);
                if(flag) ans++;
                flag = true;
            }

    cout<<ans<<endl;
}