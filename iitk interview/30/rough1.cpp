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
int grid[28][28],dist[28][28];
int w,h,n;
int ans = INT_MAX;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
void bfs(){
    queue<pii> q;int maxi = 0;
    int dist[h][w];
    memset(dist,-1,sizeof(dist));
    f(i,0,h){
        f(j,0,w){
            dist[i][j] = grid[i][j];
            if(dist[i][j] == 0)
                q.push({i,j});
        }
    }
     
    while(!q.empty()){
        int r = q.front().fi,c = q.front().se;
        q.pop();
        maxi = max(maxi,dist[r][c]);
        for(int d = 0; d < 4; d++){
            int newr = r + dx[d];
            int newc = c + dy[d];
            if(newr<0 || newr>=h || newc<0 || newc>=w)
                continue;
            if(dist[newr][newc]==-1){
                dist[newr][newc] = dist[r][c] + 1;
                q.push({newr,newc});
            }
        }
    }
    ans = min(ans,maxi);
}
void solve(int left, int r, int c){
    if(left==0) bfs();
    if(c==w){r++;c = 0;}
    if(r>=h) return;
    for(int i = r;i<h;i++){
        for(int j = c;j<w;j++){
            grid[i][j] = 0;
            solve(left-1,i,j+1);
            grid[i][j] = -1;
        }
    }
}
int main(){
    scanf("%d%d%d",&w,&h,&n);
    for(int i = 0;i<h;i++)
        for(int j = 0;j<w;j++)
            grid[i][j] = -1;
    solve(n,0,0);
    cout<<ans<<endl;
}