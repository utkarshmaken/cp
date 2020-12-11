//URJANET 
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
    string n;
    cin>>n;
    int k,q;
    cin>>k>>q;
    vector<bool> poss(k);
    int len = sz(n);
    int dp[len][k];
    memset(dp,0,sizeof(dp));
    dp[0][(n[0]-'0')%k] = 1;
    f(i,1,len){
        int dig = n[i] - '0';
        f(j,0,k){
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
            dp[i][(10*j + dig)%k] = max(dp[i][(10*j + dig)%k], dp[i-1][j]);
        }
    }
    f(i,0,q){
        int x;cin>>x;
        if(x>=k){
            cout<<"No"<<endl;
            continue;
        }

        if(dp[len-1][x] == 1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}