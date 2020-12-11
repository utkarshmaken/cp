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
const int maxn = 2000000;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,z;
        cin>>n>>k>>z;
        vector<int> a(n);
        f(i,0,n) cin>>a[i];

        vector<int> pairs(k+1);
        pairs[0] = 0;
        rep(i,1,k)
            pairs[i] = max(pairs[i-1],a[i-1] + a[i]);
        int ans = 0;
        int ma = max(1,k-2*z);
        rep(i,0,ma)
             ans+=a[i];
        int res = ans; 
        rep(i,ma,k){
            int rem = (k-i);
            int add = 0;
            if(rem%2==0)
                add = pairs[i]*(rem/2);
            else
                add = pairs[i]*(rem/2) + a[i-1];
            res = max(res,ans+add);
            ans+=a[i+1];
        }
        cout<<res<<endl;
    }
}