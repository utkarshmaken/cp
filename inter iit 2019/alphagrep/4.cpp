//IMAGE MATCHING
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
int n,m;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
void dfs(vector<vector<int>> &grid, int i, int j, set<pii> &s, vector<vector<bool>> &visited){
    visited[i][j] = true;
    s.insert({i,j});
    for(int d = 0;d<4;d++){
        int ni = i+dx[d],nj = j+dy[d];
        if(ni<0 || nj<0 || ni>=n || nj>=m || grid[ni][nj]==0 || visited[ni][nj])
            continue;
        dfs(grid,ni,nj,s,visited);
    }
}
int main(){
    cin>>n>>m;
    vector<vector<int>> grid1(n,vector<int>(m));
    vector<vector<int>> grid2(n,vector<int>(m));
    f(i,0,n) f(j,0,m) cin>>grid1[i][j];
    f(i,0,n) f(j,0,m) cin>>grid2[i][j];
    set<set<pii>> comp1,comp2;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    set<pii> s;
    f(i,0,n)
        f(j,0,m)
            if(!visited[i][j] && grid1[i][j]==1){
                dfs(grid1,i,j,s,visited);
                comp1.insert(s);
                s.clear();
            }
    visited = vector<vector<bool>>(n,vector<bool>(m,false));
    s.clear();
    f(i,0,n)
        f(j,0,m)
            if(!visited[i][j] && grid2[i][j]==1){
                dfs(grid2,i,j,s,visited);
                comp2.insert(s);
                s.clear();
            }
    vector<set<pii>> ans;
    set_intersection(all(comp1),all(comp2),back_inserter(ans));
    cout<<ans.size()<<endl;
}