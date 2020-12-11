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
    int n,m,t;
    cin>>n>>m;
    vector<int> h(n+1,1),v(m+1,1);
    int x,y;
    cin>>x;
    f(i,0,x) cin>>t,h[t] = 0;
    cin>>y;
    f(i,0,y) cin>>t,v[t] = 0;
    ll ht = 0,wi = 0;
    int start = 0;
    rep(i,1,n){
        if(h[i]==0) continue;
        else{
            ht = max(ht,1ll*(i-start));
            start = i;
        }
    }
    ht = max(ht,1ll*(n+1-start));
    start = 0;
    rep(i,1,m){
        if(v[i]==0) continue;
        else{
            wi = max(wi,1ll*(i-start));
            start = i;
        }
    }
    wi = max(wi,1ll*(m+1-start));
    cout<<ht*wi<<endl;

}