//MINIMUM PRICE
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
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    f(i,0,n) cin>>a[i];
    ll ans = 0;
    f(i,0,n){
        ll mini = a[i];
        f(j,i+1,n) mini = min(mini,(j-i)*x + a[j]);
        f(j,0,i) mini = min(mini,(i-j)*x + a[j]);
        ans+=mini;
    }
    cout<<ans<<endl;






}