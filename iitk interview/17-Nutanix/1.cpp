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
#define mp make_pair
#define pb push_back
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
using namespace std;
const int mod = 1000000007;
const int maxn = 1e5+5;
ll dp[maxn][2];
vector<int> adj[maxn];
vector<int> arr(maxn),brr(maxn);
void solve(int u,int p){
    for(int &v:adj[u]){
        if(v!=p)
            solve(v,u);
    }
    ll ans1 = 0,ans2 = 0;
    for(int &v:adj[u]){
        if(v!=p){
            ans1+=dp[v][0];
            ans2+=dp[v][1];
        }
    }
    if(arr[u] == brr[u]){
        dp[u][0] = min(ans1,2+ans2);
        dp[u][1] = min(1+ans1,1+ans2);
    }
    else{
        dp[u][0] = min(1+ans1,1+ans2);
        dp[u][1] = min(2+ans1,ans2);
    }

}

int main (){
        int n;
        scanf("%d",&n);
        f(i,0,n-1){
            int a,b;
            scanf("%d%d",&a,&b);
            adj[a].pb(b);
            adj[b].pb(a);
        }
        rep(i,1,n) scanf("%d",&arr[i]);
        rep(i,1,n) scanf("%d",&brr[i]);
        solve(1,-1);
        cout<<dp[1][0]<<endl;

}