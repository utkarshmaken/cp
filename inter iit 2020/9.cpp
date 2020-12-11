//DARK MAGIC
//BASED ON TERNARY SEARCH
//OR SIMPLY MERGE TWO ARRAYS(NICE METHOD)
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
const int maxn = 2e5;

int main(){
    int n,m;
    cin>>n;
    vector<int> g(n);
    f(i,0,n) cin>>g[i];
    cin>>m;
    vector<int> s(m);
    f(i,0,m) cin>>s[i];
    sort(all(g));sort(all(s));

    vector<int> sumg(n+1),sums(m+1);
    f(i,0,n) sumg[i+1] = sumg[i] + g[i];
    f(i,0,m) sums[i+1] = sums[i] + s[i];
    vector<int> nums(n+m);
    f(i,0,n) nums[i] = g[i];
    f(i,n,n+m) nums[i] = s[i-n];
    sort(all(nums));
    int ans = INT_MAX;
    f(i,0,n+m){
        int x = nums[i];
        int s1,s2;
        auto it = upper_bound(all(g),x);
        if(it == g.end()) s1 = 0;
        else{
            int idx = it - g.begin();
            s1 = (sumg[n] - sumg[idx]) - (n-idx)*x;
        }
        it = lower_bound(all(s),x);
        if(it == s.begin()) s2 = 0;
        else{
            --it;
            int idx = it - s.begin();
            s2 = (idx+1)*x - sums[idx+1];
        }
        ans = min(ans,s1+s2);
    }
    cout<<ans<<endl;
}