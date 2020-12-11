//HUNGRY KNIGHT
#include <bits/stdc++.h>
#define pii pair<int,int> 
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl '\n'
using namespace std;

int dist[9][8][8];
int dp[10][1025];
vector<pii> pawns;
int allones;
int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {-1,1,-2,2,-2,2,-1,1};

void bfs(int &r, int &c, int idx){
    queue<pii> q;
    vector<vector<bool>> visited(8,vector<bool>(8));
    q.push({r,c});dist[idx][r][c] = 0;visited[r][c] = true;
    int steps = 1;
    while(!q.empty()){
        for(int t = q.size();t>0;--t){
            int r = q.front().fi,c = q.front().se;
            q.pop();
            for(int d = 0;d<8;d++){
                int nr = r+dx[d],nc = c+dy[d];
                if(nr<0 || nc<0 || nr>=8 || nc>=8 || visited[nr][nc])
                    continue;
                visited[nr][nc] = true;
                dist[idx][nr][nc] = steps;
                q.push({nr,nc});
            }
        }
        ++steps;
    }
}

int find(int r, int c, int idx, int mask, int &n){
    if(mask == allones) return 0;
    if(dp[idx][mask]!=-1) return dp[idx][mask];
    int mini = INT_MAX;
    for(int i = 1;i<=n;i++){
        if((mask & (1<<i)) == 0){
            int nmask = mask | (1<<i);
            int nr = pawns[i-1].fi,nc = pawns[i-1].se;
            mini = min(mini,dist[idx][nr][nc] + find(nr,nc,i,nmask,n));
        }
    }
    return dp[idx][mask] = mini;
}

int main(){
    int grid[8][8];
    string s;cin>>s;
    s = s+'/';
    int len = s.size();
    int pos = s.find('/'),curr = 0,i = 0;
    int r,c;
    while(pos < len){
        string row = s.substr(curr,pos - curr);
        int idx = 0;
        for(auto &x:row){
            if(x>='0' && x<='8'){
                int d = x-'0';
                for(int rep = 1;rep<=d;++rep) grid[i][idx++] = 0;
            }
            else if(x == 'p'){
                grid[i][idx] = 1;
                pawns.pb({i,idx});
                ++idx;
            }
            else if(x == 'n'){
                r = i;
                c = idx++;
                grid[r][c] = 2;
            }
        }
        curr = ++pos;
        if(pos == len) break;
        pos = s.find('/',pos);
        ++i;
    }

    int n = pawns.size();
    memset(dist,-1,sizeof(dist));
    bfs(r,c,0);
    for(int i = 0;i<n;i++) bfs(pawns[i].fi,pawns[i].se,i+1);
    allones = (1<<(n+1)) - 1;
    memset(dp,-1,sizeof(dp));
    cout<<find(r,c,0,1,n)<<endl;
}