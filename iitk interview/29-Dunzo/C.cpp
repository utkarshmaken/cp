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
const int maxn = 100001;
int n,m,x,y,num,allones;
int arr[101][101],dp[17][maxn],dist[101][101][17];
vector<pii> dir = {{-1,0},{0,-1},{0,1},{1,0}};
vector<pii> coins;

void setDistance(int i){
    f(r,0,n) f(c,0,m) dist[r][c][i] = INT_MAX;
    vector<vector<bool>> visited(n,vector<bool>(m));
    queue<pii> q;
    q.push(coins[i]);visited[coins[i].fi][coins[i].se] = true;
    dist[coins[i].fi][coins[i].se][i] = 0;
    while(!q.empty()){
        int r = q.front().fi,c = q.front().se;
        q.pop();
        for(auto p:dir){
            int newr = r+p.fi,newc = c+p.se;
            if(newr<0 || newr>=n || newc<0 || newc>=m || visited[newr][newc] || arr[newr][newc]==1)
                continue;
            visited[newr][newc] = true;
            dist[newr][newc][i] = dist[r][c][i]+1;
            q.push({newr,newc});
        }
    }

}
ll getDistance(int i, int seq){
    if(seq==allones) return dist[x][y][i];
    if(dp[i][seq]!=-1) return dp[i][seq];

    ll ans = INT_MAX;
    f(j,0,num){
        if((seq&(1<<j))==0){
            int nseq = seq | (1<<j);
            int r = coins[j].fi,c = coins[j].se;
            ans = min(ans, dist[r][c][i] + getDistance(j,nseq));
        }
    }
    dp[i][seq] = ans;
    return ans;
}

int main(){
    cin>>n>>m;
    f(i,0,n) f(j,0,m) cin>>arr[i][j];
    cin>>x>>y;
    coins.pb({0,0});
    f(i,0,n)
        f(j,0,m) 
            if(arr[i][j]==2) 
                coins.pb({i,j});

    num = sz(coins);allones = (1<<num)-1;
    f(i,0,num) 
        rep(j,0,allones) 
            dp[i][j] = -1;

    f(i,0,num) setDistance(i);
    ll ans  = getDistance(0,1);
    if(ans==INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;

}