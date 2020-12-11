//ANGRY ANIMALS
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
    int n,m;cin>>n>>m;
    vector<int> a(m),b(m);
    f(i,0,m) cin>>a[i];
    f(i,0,m) cin>>b[i];
    vector<int> reach(n+1,n);
    f(i,0,m){
        int x = min(a[i],b[i]);
        int y = max(a[i],b[i]);
        reach[x] = min(reach[x],y-1);
    }
    int ans = 1;
    repd(i,n-1,1){
        reach[i] = min(reach[i],reach[i+1]);
        ans+=(reach[i] - i + 1);
    }
    cout<<ans<<endl;
}