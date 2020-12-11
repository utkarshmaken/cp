//BUILD OFFICES
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
int h,w,n;
int dist[28][28];
bool visited[28][28];
int ans = INT_MAX;
vector<pii> points;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

void bfs(){
    queue<pii> q;
    f(i,0,h){
        f(j,0,w){
            dist[i][j] = 0;
            visited[i][j] = false;
        }
    }
    for(auto &p:points){
        q.push(p);
        visited[p.fi][p.se] = true;
    }

    int steps = 1;
    while(!q.empty()){
        for(int rep = q.size();rep>0;--rep){
            int r = q.front().fi,c = q.front().se;
            q.pop();
            for(int d = 0;d<4;++d){
                int nr = r+dx[d],nc = c+dy[d];
                if(nr<0 || nc<0 || nr>=h || nc>=w || visited[nr][nc])
                    continue;
                dist[nr][nc] = steps;
                visited[nr][nc] = true;
                q.push({nr,nc});
            }
        }
        if(!q.empty())
            ++steps;
    }
    ans = min(ans,steps-1);
}
void find(int rem, int r, int c){
    if(rem==0){
        bfs();
        return;
    }
    if(c == w){
        r = r+1;
        c = 0;
    }
    if(r>=h) return;

    for(int i = r;i<h;i++){
        for(int j = 0;j<w;j++){
            if(i==r && j<c) continue;
            points[n-rem] = {i,j};
            find(rem-1,i,j+1);
        }
    }
}
int main(){
    cin>>h>>w>>n;
    points.resize(n);
    find(n,0,0);
    cout<<ans<<endl;
}