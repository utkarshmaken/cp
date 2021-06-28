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

int n,k;
vector<int> h;
int dp[4001][4001];

void find(int i, int h1, int h2){
    if(h1 >= k && h2 >= k){
        if(dp[k][k] == -1) dp[k][k] = i;
        else dp[k][k] = min(dp[k][k],i);
        return;
    }
    if(i == n)
        return;
    if(h1 >= k){
        if(dp[k][h2] == -1) dp[k][h2] = i;
        find(i+1,h1,h2+h[i]);

    }
    else if(h2 >= k){
        if(dp[h1][k] == -1) dp[h1][k] = i;
        find(i+1,h1+h[i],h2);
    }
    else if(dp[h1][h2] == -1){
        dp[h1][h2] = i;
        find(i+1,h1+h[i],h2);
        find(i+1,h1,h2+h[i]);
    }
}

int main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>k;
        h.resize(n);
        f(i,0,n) cin>>h[i];
        sort(all(h),greater<int>());
        int i = 0;
        while(i < n && h[i] >= k) ++i;
        if(i >= 2){
            cout<<2<<endl;
            continue;
        }
        if(i == 1){
            int sum = 0;
            while(i < n && sum < k){
                sum += h[i++];
            }
            if(sum < k) cout<<-1<<endl;
            else cout<<i<<endl;
            continue;
        }
        int h1 = h[0], h2 = 0;
        memset(dp,-1,sizeof(dp));
        find(1,h1,h2);
        cout<<dp[k][k]<<endl;
    }
}