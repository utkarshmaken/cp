//GROWTH IN 2 DIMENSIONS
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
    int n;
    cin>>n;
    vector<pii> arr(n);
    f(i,0,n) cin>>arr[i].fi>>arr[i].se;
    int rmin  = arr[0].fi,cmin = arr[0].se;
    f(i,1,n){
        rmin = min(rmin,arr[i].fi);
        cmin = min(cmin,arr[i].se);
    }
    cout<<rmin*cmin<<endl;


}