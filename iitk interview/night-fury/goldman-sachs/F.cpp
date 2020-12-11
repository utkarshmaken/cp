//WORD PUZZLE
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
const int maxn = 100001;
int n,len;
string s;
int find(vector<string> &grid, int r, int c){
    int ans = 0;
    int i;
    if(r+len-1<n){
        i = r;
        for(;i<r+len;i++)
            if(grid[i][c]!=s[i-r]) break;
        if(i==r+len) ++ans;
    }
    if(r-len+1>=0){
        i = r;
        for(;i>r-len;i--)
            if(grid[i][c]!=s[r-i]) break;
        if(i==r-len) ++ans;
    }
    if(c+len-1<n){
        i = c;
        for(;i<c+len;i++)
            if(grid[r][i]!=s[i-c]) break;
        if(i==c+len) ++ans;
    }
    if(c-len+1>=0){
        i = c;
        for(;i>c-len;i--)
            if(grid[r][i]!=s[c-i]) break;
        if(i==c-len) ++ans;
    }
    if(r+len-1<n && c+len-1<n){
        i = 0;
        for(;i<len;i++)
            if(grid[r+i][c+i]!=s[i]) break;
        if(i==len) ++ans;
    }
    if(r-len+1>=0 && c-len+1>=0){
        i = 0;
        for(;i<len;i++)
            if(grid[r-i][c-i]!=s[i]) break;
        if(i==len) ++ans;
    }
    if(r-len+1>=0 && c+len-1<n){
        i = 0;
        for(;i<len;i++)
            if(grid[r-i][c+i]!=s[i]) break;
        if(i==len) ++ans;
    }
    if(r+len-1<n && c-len+1>=0){
        i = 0;
        for(;i<len;i++)
            if(grid[r+i][c-i]!=s[i]) break;
        if(i==len) ++ans;
    }
    return ans;
}
int main(){
    cin>>n;
    vector<string> grid(n);
    f(i,0,n) cin>>grid[i];
    cin>>s;
    len = sz(s);
    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j =0;j<n;j++){
            if(grid[i][j]==s[0])
                ans+=find(grid,i,j);
        }
    }
    cout<<ans<<endl;
}