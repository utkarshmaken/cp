//LASER GRID
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
    int r,c;cin>>r>>c;
    int xi,yi,xf,yf;
    cin>>xi>>yi>>xf>>yf;
    vector<int> costx(r-1),costy(c-1);
    int t;cin>>t;
    f(i,0,r-1) cin>>costx[i];
    cin>>t;
    f(i,0,c-1) cin>>costy[i];

    vector<vector<bool>> visited(r,vector<bool>(c));
    vector<vector<int>> dist(r,vector<int>(c,INT_MAX));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
    pq.push({0,xi,yi});dist[xi][yi] = 0;

    while(!pq.empty()){
        vector<int> v = pq.top();
        int di = v[0],x = v[1],y = v[2];
        pq.pop();
        if(visited[x][y])
            continue;
        visited[x][y] = true;
        for(int d = 0;d<4;++d){
            int nx = x+dx[d],ny = y+dy[d];
            if(nx<0 || ny<0 ||nx>=r || ny>=c) continue;
            if((d==0 || d==3) && dist[nx][ny] > di + costx[x]){
                dist[nx][ny] = di + costx[x];
                pq.push({dist[nx][ny],nx,ny});
            }
            if((d==1 || d==2) && dist[nx][ny] > di + costy[y]){
                dist[nx][ny] = di + costy[y];
                pq.push({dist[nx][ny],nx,ny});
            }
        } 
    }
    cout<<dist[xf][yf]<<endl;

    


}