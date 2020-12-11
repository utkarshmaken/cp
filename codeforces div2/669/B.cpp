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
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        f(i,0,n) cin>>a[i];
        sort(all(a),greater<int>());
        vector<int> ans(n);ans[0] = a[0];
        vector<int> vis(n);vis[0] = 1;
        int curr = a[0];
        for(int i = 1;i<n;i++){
            int maxi = 0,idx;
            for(int j = 0;j<n;j++){
                if(vis[j]) continue;
                int g = __gcd(curr,a[j]);
                if(g>maxi){
                    maxi = g;
                    idx = j;
                }
            }
            ans[i] = a[idx];
            curr = maxi;
            vis[idx] = true;
        }
        for(auto &x:ans) cout<<x<<' ';
        cout<<endl;





    }

}