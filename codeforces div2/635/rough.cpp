//https://codeforces.com/contest/475/problem/B
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
int n,m;
string horz,vert;
bool reachable(int i, int j){
    vector<vector<bool>> visited(n,vector<bool>(m));
    queue<pii> q;
    q.push({0,0});visited[0][0] =true;
    while(!q.empty()){
        int i = q.front().fi,j = q.front().se;
        q.pop();
        
        int i1 = i,j1 = horz[i] == '>'?j+1:j-1;
        int j2 = j,i2 = vert[j] == 'v'?i+1:i-1;
        
        if(!(j1<0 || j1==m || visited[i1][j1])){
            q.push({i1,j1});
            visited[i1][j1] = true;
        }
        if(!(i2<0 ||i2==n || visited[i2][j2])){
            q.push({i2,j2});
            visited[i2][j2] = true;
        }
    }
    f(i,0,n)
        f(j,0,m)
            if(!visited[i][j])
                return false;
    return true;
}
int main(){
    cin>>n>>m;
    cin>>horz;
    cin>>vert;
    if(!reachable(0,0)){
        cout<<"NO"<<endl;
        return 0;
    }
    f(i,0,n) horz[i] = horz[i]=='<'?'>':'<';
    f(i,0,m) vert[i] = vert[i]=='v'?'^':'v';
    if(!reachable(0,0)){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;

}
