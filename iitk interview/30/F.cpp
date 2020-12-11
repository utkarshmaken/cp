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
const int maxn = 100001;
vector<ll> a(maxn),temp(maxn);
ll find_inc(int i, int &n){
    if(i==n-1) return 0;
    ll ans = 1e18;
    
    
}
int main(){
    int n;
    cin>>n;
    f(i,0,n) cin>>a[i];
    temp = a;
    ll ans = 0;
    ans = find_inc(0,n);
    a = temp;
    reverse(a.begin(),a.begin()+n);
    ans = min(ans,find_inc(0,n));
    cout<<ans<<endl;
}