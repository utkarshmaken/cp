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
    int n;cin>>n;
    vector<int> a(n);
    f(i,0,n) cin>>a[i];
    ll k;cin>>k;
    sort(all(a),greater<int>());
    ll ans = 0;
    ll tick = 1,curr = a[0],idx = 0;
    while(k>0){
        while(idx+1<n && a[idx+1]==curr){
            tick++;idx++;
        }
        ll nxt = 0;
        if(idx+1<n) nxt = a[idx+1];
        while(k>0 && curr>nxt){
            ans+=curr*min(k,tick);
            k-=min(k,tick);
            curr--;
        }
        curr = nxt;
        tick++;
        idx++;
    }
    cout<<ans<<endl;

}