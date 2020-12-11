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
#define mp make_pair
#define pb push_back
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
using namespace std;
const int mod = 1000000007;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a,b,both;
    f(i,0,n){
        int t,x,y;
        cin>>t>>x>>y;
        if(x&y) both.pb(t);
        else if(x) a.pb(t);
        else if(y) b.pb(t);
    }
    sort(all(a));sort(all(b));
    f(i,0,min(sz(a),sz(b)))
        both.pb(a[i]+b[i]);
    sort(all(both));
    if(sz(both)<k)
        cout<<-1<<endl;
    else{
        ll ans = 0;
        f(i,0,k) ans+=both[i];
        cout<<ans<<endl;
    }
}