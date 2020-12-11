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
const int maxn = 1e5;
int dirx[4] = {-1,0,0,1};
int diry[4] = {0,-1,1,0};

int main(){
    int n;cin>>n;
    vector<string> grid(n);
    f(i,0,n) cin>>grid[i];
    int sx,sy,dx,dy;
    cin>>sx>>sy>>dx>>dy;
    map<char,int> m;
    m['U'] = 0;m['L'] = 1;m['R'] = 2;m['D'] = 3;
    vector<vector<bool>> visited(n,vector<bool>(n));
    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0,sx,sy});dist[sx][sy] = 0;
    while(!pq.empty()){
        int d = pq.top()[0],r = pq.top()[1],c = pq.top()[2];
        pq.pop();
        if(visited[r][c])
            continue;
        if(r == dx && c == dy){
            cout<<d<<endl;
            break;
        }
        visited[r][c] = true;
        for(int rep = 0;rep<4;rep++){
            int nr = r+dirx[rep], nc = c+diry[rep];
            if(nr<0 || nc<0 || nr>=n || nc>=n)
                continue;
            if(m[grid[r][c]] == rep){
                if(dist[nr][nc] > d){
                    dist[nr][nc] = d;
                    pq.push({d,nr,nc});
                }
            }
            else{
                if(dist[nr][nc] > d+1){
                    dist[nr][nc] = d+1;
                    pq.push({d+1,nr,nc});
                }
            }
            
        }
    }


}