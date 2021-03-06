//TRIANGULAR SUBSEQUENCE
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
int main(){
    int n;cin>>n;
    vector<int> a(n);
    f(i,0,n) cin>>a[i];
    sort(all(a));
    int ans = 0;
    f(i,0,n-2){
        int s = a[i] + a[i+1];
        auto it = lower_bound(all(a),s);
        --it;
        int idx = it-a.begin();
        ans = max(ans,idx-i+1);
    }
    cout<<ans<<endl;


}