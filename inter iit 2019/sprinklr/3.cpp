//INTERESTING PRIME
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
const int maxn = 1000001;
vector<int> dp(maxn);
vector<int> prime(maxn,1);
unordered_set<int> s2,s4;
void find_prime(){
    int n = maxn-1;
    prime[1] = 0;
    for(int i = 2;i*i<=n;i++){
        if(prime[i] == 0) continue;
        for(int j = i*i;j<=n;j+=i)
            prime[j] = 0;
    }
}
int check(int n){
    for(auto x:s4){
        if(s2.find(n-x)!=s2.end()) return 1;
    }
    return 0;
}
int main(){
    rep(i,1,1000)  s2.insert(i*i);
    rep(i,1,32) s4.insert(pow(i,4));
    find_prime();
    dp[1] = 0;dp[2] = 1;
    f(i,3,maxn){
        dp[i] = dp[i-1];
        if(prime[i]) dp[i]+=check(i);
    }
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
}