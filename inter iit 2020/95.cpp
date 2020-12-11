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
const ll mod = 1000000007;
const int maxn = 1e5;

int main(){
    int n;cin>>n;
    vector<pii> points;
    f(i,0,n) cin>>points[i].fi>>points[i].se;
    map<int,set<int>> mx,my;
    f(i,0,n){
        mx[points[i].fi].insert(points[i].se);
        my[points[i].se].insert(points[i].fi);
    }
    int ans = 0;
    set<pii> vis;
    for(auto it:mx){
        set<int> &s = it.se;
        for(auto it = s.begin)




    }


}