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
 
int main(){
    int n;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    vector<int> mini(n+1,n+1);
    vector<int> a(m),b(m);
    f(i,0,m) scanf("%d",&a[i]);
    scanf("%d",&m);
    f(i,0,m) scanf("%d",&b[i]);
    f(i,0,m){
        int a1 = a[i],b1 = b[i];
        if(a1>b1) swap(a1,b1);
        mini[a1] = min(mini[a1],b1);
    }
    repd(i,n-1,1) mini[i] = min(mini[i],mini[i+1]);
    ll ans = 0;
    rep(i,1,n) ans+=mini[i]-i;
    cout<<ans<<endl;

}