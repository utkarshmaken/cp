//BOB NAVIGATES A MAZE
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
int dist[11][100][100];
int grid[100][100];
int n,m;
int x,y;
vector<pii> coins;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int allones,len;
int dp[11][3000];
void bfs(int r, int c, int idx){
    vector<vector<bool>> visited(n,vector<bool>(m));
    queue<pii> q;
    q.push({r,c});dist[idx][r][c] = 0;visited[r][c] = true;
    int steps = 1;
    while(!q.empty()){
        for(int rep = q.size();rep>0;--rep){
            int r = q.front().fi,c = q.front().se;
            q.pop();
            for(int d = 0;d<4;++d){
                int nr = r+dx[d],nc = c+dy[d];
                if(nr<0 || nc<0 ||nr>=n || nc>=m || grid[nr][nc]==1 || visited[nr][nc])
                    continue;
                visited[nr][nc] = true;
                dist[idx][nr][nc] = steps;
                q.push({nr,nc});
            }
        }
        ++steps;
    }
}
int find(int r, int c, int mask, int idx){
    if(mask == allones){
        if(dist[idx][x][y] == -1) return INT_MAX;
        return dist[idx][x][y];
    }
    if(dp[idx][mask]!=-1) return dp[idx][mask];
    int ans = INT_MAX;
    for(int i = 1;i<=len;i++){
        if((mask & (1<<i)) == 0){
            int nmask = (mask | (1<<i));
            int nr = coins[i-1].fi,nc = coins[i-1].se;
            int d = dist[idx][nr][nc];
            if(d == -1) continue;
            int res = find(nr,nc,nmask,i);

            if(res!=INT_MAX) ans = min(ans,d+res);
        }
    }
    return dp[idx][mask] = ans;
}
int main(){
    cin>>n>>m;
    f(i,0,n) f(j,0,m) cin>>grid[i][j];
    cin>>x>>y;
    f(i,0,n)
        f(j,0,m)
            if(grid[i][j] == 2)
                coins.pb({i,j});
    len = coins.size();
    memset(dist,-1,sizeof(dist));
    bfs(0,0,0);
    rep(i,1,len) bfs(coins[i-1].fi,coins[i-1].se,i);
    allones = (1<<(len+1)) - 1;
    memset(dp,-1,sizeof(dp));
    int ans = find(0,0,1,0);
    if(ans == INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;
}