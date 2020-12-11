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
    int n;
    scanf("%d",&n);
    vector<ll> a(n);
    f(i,0,n) scanf("%lld",&a[i]);
    int k;
    scanf("%d",&k);
    vector<ll> dp(n);
    dp[n-1] = a[n-1];
    deque<int> q;q.push_back(n-1);
    repd(i,n-2,0){
        while(q.front()>i+k) q.pop_front();
        dp[i] = a[i] + dp[q.front()];
        while(!q.empty() && dp[q.back()]<=dp[i]) q.pop_back();
        q.push_back(i);
    }
    cout<<dp[0]<<endl;
}
