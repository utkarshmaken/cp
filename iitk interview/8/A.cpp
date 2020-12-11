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
    vector<int> v(n);
    f(i,0,n) cin>>v[i];
    vector<int> sum(n+1);
    rep(i,1,n) sum[i] = sum[i-1] + (v[i-1]==1);
    f(ans,0,n){
        int myscore = 2*sum[ans] - ans;
        int frscore = 2*(sum[n] - sum[ans]) - (n-ans);
        if(myscore > frscore){
            cout<<ans<<endl;
            return 0;
        }
    }
}