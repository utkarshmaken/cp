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
const int maxn = 2000000;
int main(){
    int t;
    scanf("%d",&t);
    rep(_,1,t){
        int n,m;
        scanf("%d%d",&n,&m);
        vector<string> s(n);
        f(i,0,n) cin>>s[i];
        vector<vector<bool>> poss(n+1,vector<bool>(m+1));
        poss[n][m-1] = true;
        repd(i,n-1,0)
            repd(j,m-1,0)
                if(s[i][j]!='#' && (poss[i][j+1]||poss[i+1][j]))
                   poss[i][j] = true;
        
        string ans(m+n-1,'?');
        ans[0] = s[0][0];
        vector<vector<bool>> visited(n+1,vector<bool>(m+1));
        visited[0][0] = true;
        for(int ind = 1;ind<n+m-1;ind++){
            char mini = 'z';
            for(int i = max(0,ind-m+1);i<min(n,ind+1);i++){
                int j = ind-i;
                if(j>=m) continue;
                if(poss[i][j])
                    if((i>=1 &&visited[i-1][j]) || (j>=1 && visited[i][j-1]))
                        if(s[i][j]<=mini)
                            mini = s[i][j];
            }
            ans[ind] = mini;
            for(int i = max(0,ind-m+1);i<min(n,ind+1);i++){
                int j = ind-i;
                if(j>=m) continue;
                if(poss[i][j])
                    if((i>=1 &&visited[i-1][j]) || (j>=1 && visited[i][j-1]))
                        if(s[i][j]==mini)
                            visited[i][j] = true;
            }
        }
        cout<<ans<<endl;

    }

}