//GP IN A ARRAY
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
#define mp make_pair
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
#define endl '\n'
using namespace std;
const int mod = 1000000007;
const int maxn = 1e6;
map<int,set<int>> m;
map<vector<int>,int> dp;
long find(int r, int k, int i, int ele){
    if(k == 1) return 1;
    int next = ele*r;
    long res = 0;
    if(m.find(next) == m.end()) return 0;
    auto it = m[next].upper_bound(i);
    while(it!=m[next].end()){
        if(dp.find({*it,k-1,r}) == dp.end())
            dp[{*it,k-1,r}] = find(r,k-1,*it,next);
        res+=dp[{*it,k-1,r}];
        ++it;
    }
    return dp[{i,k,r}] = res;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    int maxi = 0;
    f(i,0,n){
        cin>>arr[i];
        maxi = max(maxi,arr[i]);
    }
    
    f(i,0,n) m[arr[i]].insert(i);
    int maxir = pow(maxi,1.0/(k-1)) + 2;
    vector<int> prime(1+maxir,1);
    prime[1] = 0;
    for(int i = 2;i*i<=maxir;i++){
        if(prime[i] == 0) continue;
        for(int j = i*i;j<=maxir;j+=i)
            prime[j] = 0;
    }
    long ans = 0;
    rep(r,2,maxir){
        if(!prime[r]) continue;
        rep(i,0,n-k){
            ans = (ans + find(r,k,i,arr[i]))%mod;
        }
    }
    cout<<ans<<endl;
}