//Set1--CitySkylines
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
    vector<int> a(n),b(m);
    f(i,0,n) cin>>a[i];
    f(i,0,m) cin>>b[i];
    //minimum
    multiset<int> br;
    f(i,0,m) br.insert(b[i]);
    ll mini = 0;
    f(i,0,n){
        int h = a[i];
        mini+=h;
        if(br.find(h)!=br.end()){
           br.erase(br.find(h));
        }
    }
    for(auto x:br) mini+=x;
    //maximum
    sort(all(b));
    vector<ll> sum(m+1);
    rep(i,1,m) sum[i] = b[i-1] + sum[i-1];
    ll maxi = 0;
    f(i,0,n){
        int h = a[i];
        int idx = lower_bound(all(b),h) - b.begin();
        maxi+=(m-idx)*h + sum[idx];
    }
    cout<<mini<<' '<<maxi<<endl;

}