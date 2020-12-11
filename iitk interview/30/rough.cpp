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
int grid[28][28];
int w,h,n;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(){
    queue<pii> q;int maxi = 0;
    int dist[w][h];
    memset(dist,-1,sizeof(dist));
    f(i,0,w){
        f(j,0,h){
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
            if(newr<0 || newr>=w || newc<0 || newc>=h)
                continue;
            if(dist[newr][newc]==-1){
                dist[newr][newc] = dist[r][c] + 1;
                q.push({newr,newc});
            }
        }
    }

   return maxi;
}
int solve(int left, int r, int c){
    if(left==0) 
        return bfs();

    if(c==h){
         r++;c=0;
    }
    
    int mini = INT_MAX;
    f(i,r,w){
        f(j,c,h){
            grid[i][j] = 0;
            mini = min(mini,solve(left-1,i,j+1));
            grid[i][j] = -1;
        }
    }
   
    return mini;
}
int main(){
    cin>>w>>h>>n;
    memset(grid,-1,sizeof(grid));
    cout<<solve(n,0,0)<<endl;
}
