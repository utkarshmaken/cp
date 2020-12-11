//REACH THE END IN TIME
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
int main(){
    int n;cin>>n;
    vector<string> grid(n);
    f(i,0,n) cin>>grid[i];
    int m = grid[0].size();
    int max_time;cin>>max_time;
    vector<vector<bool>> visited(n,vector<bool>(m));
    queue<pii> q;
    q.push({0,0});visited[0][0] = true;
    int steps = 0;
    bool poss = false;
    while(!q.empty()){
        for(int rep = q.size();rep>0;--rep){
            int r = q.front().fi,c = q.front().se;
            if(r==n-1 && c==m-1){
                poss = true;break;
            }
            q.pop();
            for(int d = 0;d<4;d++){
                int nr = r+dx[d],nc = c+dy[d];
                if(nr<0 || nc<0 ||nr>=n ||nc>=m ||grid[nr][nc]=='#' || visited[nr][nc])
                    continue;
                visited[nr][nc] = true;
                q.push({nr,nc});
            }
        }
        if(poss) break;
        ++steps;
    }
    if(poss && steps<=max_time) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}