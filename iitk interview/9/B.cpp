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
const int maxn = 200001;
vector<int> adj[maxn];
bool compare(pii &a, pii &b){
    if(a.fi==b.fi)
        return a.se < b.se;
    return a.fi>b.fi;
}
int main(){
    int n;cin>>n;
    vector<int> a(n);
    f(i,0,n) cin>>a[i];
    vector<pii> arr(n);
    f(i,0,n) arr[i].fi = a[i],arr[i].se = i;
    sort(all(arr),compare);
    vector<bool> vis(n);
    int ans = 0;
    f(i,0,n){
        if(vis[i] || arr[i].se==i) continue;

        int len = 0,j = i;
        while(!vis[j]){
            vis[j] = 1;
            ++len;
            j = arr[j].se;
        }
        ans+=len-1;
    }
    cout<<ans<<endl;
       
}