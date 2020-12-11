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
int w,h,n;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
map<pii,int> dp;
int calc(int i, int j){
    return h*i + j;
}
bool get(int mask, int i, int j){
    return (mask&(1<<calc(i,j)));
}
int bfs(int mask){
    queue<pii> q;int maxi = 0;
    int dist[w][h];
    memset(dist,-1,sizeof(dist));
    f(i,0,w)
        f(j,0,h)
            if(get(mask,i,j)){
                dist[i][j] = 0;
                q.push({i,j});
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
int solve(int left, int mask){
    if(left==0) 
        return bfs(mask);

    if(dp.find({mask,left})!=dp.end()) 
        return dp[{mask,left}];
    
    int mini = INT_MAX;
    f(i,0,w){
        f(j,0,h){
            if(!get(mask,i,j)){
                int newmask = (mask | (1<<calc(i,j)));
                mini = min(mini,solve(left-1,newmask));
            }
        }
    }
    dp[{mask,left}] = mini;
    return mini;
}
int main(){
    cin>>w>>h>>n;
    dp.clear();
    cout<<solve(n,0)<<endl;
}