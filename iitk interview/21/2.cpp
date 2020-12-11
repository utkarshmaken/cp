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
const int maxn = 200000;
vector<string> mat(maxn);
pii arr[] = {{-1,0},{0,-1},{0,1},{1,0}};
void dfs(int i, int j, int& r, int& c, char& ch,vector<vector<bool>>& visited){
    visited[i][j] = true;
    for(auto p: arr){
        int x = p.fi,y = p.se;
        if(i+x<0 || i+x>=r || j+y<0 || j+y>=c || visited[i+x][j+y] || mat[i+x][j+y]!=ch)
            continue;
        dfs(i+x,j+y,r,c,ch,visited);
    }
    
}
int main(){
        int n;
        cin>>n;
        f(i,0,n) cin>>mat[i];
        int r = n,c = sz(mat[0]);
        vector<vector<bool>> visited(r,vector<bool>(c));
        int ans = 0;
        f(i,0,r)
            f(j,0,c)
                if(!visited[i][j]){
                    ans++;
                    dfs(i,j,r,c,mat[i][j],visited);
                }

        cout<<ans<<endl;    

}