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
const int maxn = 200000;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        int amin = INT_MAX,bmin = INT_MAX;
        f(i,0,n){
            cin>>a[i];
            amin = min(amin,a[i]);
        }
        f(i,0,n){
            cin>>b[i];
            bmin = min(bmin,b[i]);
        }
        ll ans = 0;
        f(i,0,n)
            ans+=max(a[i]-amin,b[i]-bmin);
        cout<<ans<<endl;
        
    }

}