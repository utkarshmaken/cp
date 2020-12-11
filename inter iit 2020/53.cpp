//DAY ONE VISIT OFFICE
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
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

bool compare(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}
int main(){
    int n,m,y,x,p;
    cin>>n>>m>>x>>y>>p;
    int grid[n][m];
    f(i,0,n) f(j,0,m) cin>>grid[i][j];
    --x;--y;
    vector<vector<int>> pot(p,vector<int>(3));
    f(i,0,p){
        int r,c,t;
        cin>>r>>c>>t;
        --r;--c;
        pot[i] = {r,c,t};
    }
    sort(all(pot),compare);
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    queue<pii> q;
    q.push({0,0});visited[0][0] = true;
    int steps = 0;
    int idx = 0;
    int ans = -1;
    while(!q.empty()){
        while(idx<p && pot[idx][2] == steps){
            grid[pot[idx][0]][pot[idx][1]] = 1;
            ++idx;
        }
        for(int rep = q.size();rep>0;--rep){
            int r = q.front().fi,c = q.front().se;
            q.pop();
            if(r==x && c==y){
                ans = steps;
                break;
            }
            for(int d = 0;d<4;d++){
                int nr = r+dx[d],nc = c+dy[d];
                if(nr<0 || nc<0 || nr>=n || nc>=m || visited[nr][nc] || grid[nr][nc] == 1)
                    continue;
                visited[nr][nc] = true;
                q.push({nr,nc});
            }
        }
        if(ans!=-1) break;
        ++steps;
    }
    if(ans == -1) cout<<"WFH"<<endl;
    else cout<<ans-1<<endl;
}