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
    int n,m;
    cin>>n>>m;
    vector<pii> lr(m);
    vector<int> x(m);
    f(i,0,m) cin>>lr[i].fi>>lr[i].se>>x[i];
    vector<int> conq(n+1);
    set<int> s;
    rep(i,1,n) s.insert(i);
    f(i,0,m){
        int l = lr[i].fi,r = lr[i].se,win = x[i];
        auto it1 = s.lower_bound(l);
        auto it2 = s.upper_bound(r);
        vector<int> done;
        while(it1!=it2){
            int p = *it1;
            if(p!=win){
                conq[p] = win;
                done.pb(p);
            }
            ++it1;
        }
        for(auto p:done) s.erase(p);
    }
    rep(i,1,n) cout<<conq[i]<<' ';
}