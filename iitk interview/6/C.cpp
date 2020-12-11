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

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int after[n][m];
    f(i,0,n) f(j,0,m) scanf("%d",&after[i][j]);
    int before[n][m];
    before[0][0] = after[0][0];
    rep(i,1,n-1) before[i][0] = after[i][0] - after[i-1][0];
    rep(i,1,m-1) before[0][i] = after[0][i] - after[0][i-1];
    rep(i,1,n-1)
        rep(j,1,m-1)
            before[i][j] = after[i][j] - (after[i][j-1] + after[i-1][j] - after[i-1][j-1]);
    f(i,0,n) f(j,0,m) cout<<before[i][j]<<" \n"[j==m-1];
}