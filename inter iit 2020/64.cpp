//Given two strings a and b, find the number of ways to add 
//a character in a such a way that LCS(a,b) increases by 1.
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

int main(){
    string a,b;
    cin>>a>>b;
    int n = sz(a),m = sz(b);
    int lcs[n+2][m+2];
    memset(lcs,0,sizeof(lcs));
    rep(i,1,n){
        rep(j,1,m){
            if(a[i-1] == b[j-1])
                lcs[i][j] = 1 + lcs[i-1][j-1];
            else
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    int lcs_r[n+2][m+2];
    memset(lcs_r,0,sizeof(lcs_r));
    repd(i,n,1){
        repd(j,m,1){
            if(a[i-1] == b[j-1])
                lcs_r[i][j] = 1 +lcs_r[i+1][j+1]; 
            else
                lcs_r[i][j] = max(lcs_r[i+1][j],lcs_r[i][j+1]);
        }
    }

    vector<int> pos[26];
    f(i,0,m){
        int x = b[i] - 'a';
        pos[x].pb(i);
    }

    int ans = 0;
    int k = lcs[n][m];

    f(i,0,26){
        for(auto x:pos[i]){
            rep(i,0,n){
                if(1 + lcs[i][x] + lcs_r[i+1][x+2] == k+1)
                    ++ans;
            }
            
        }
    }
    cout<<ans<<endl;
}