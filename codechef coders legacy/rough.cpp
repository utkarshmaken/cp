//https://www.codechef.com/problems/FFC320G
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
//const int maxn = 2000000;
const int maxn = 1000;
int grid[maxn][maxn];
ll dp[maxn][maxn];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        f(i,0,n)
            f(j,0,m)
                cin>>grid[i][j];

        vector<string> s(n);
        f(i,0,n) cin>>s[i];

        f(i,0,m) dp[n][i] = INT_MAX;
        f(i,0,n) dp[i][m] = INT_MAX;
        dp[n-1][m] = 0;
        repd(i,n-1,0)
            repd(j,m-1,0)
                dp[i][j] = grid[i][j] + min(dp[i+1][j],dp[i][j+1]);
        
        ll val = dp[0][0];
        cout<<val<<endl;
        string ans(n+m-1,'?');
        queue<pii> q;
        q.push({0,0});        
        f(ind,0,n+m-1){
            char mini = 'z';
            queue<pii> temp = q;
            while(!q.empty()){
                pii p = q.front();
                int x = p.fi,y = p.se;
                q.pop();
                mini = min(mini,s[x][y]);
            }

            q = temp;
            queue<pii> q1;
            ans[ind] = mini;

            while(!q.empty()){
                pii p = q.front();
                int x = p.fi,y = p.se;
                q.pop();
                if(s[x][y]!=mini)
                    continue;
                if(dp[x+1][y] == dp[x][y+1])
                    q1.push({x+1,y}),q1.push({x,y+1});
                else if(dp[x+1][y] < dp[x][y+1])
                    q1.push({x+1,y});
                else
                    q1.push({x,y+1});
            }
            q = q1;
        }

        cout<<ans<<endl;

    }

}