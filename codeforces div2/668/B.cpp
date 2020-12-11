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
        vector<ll> a(n);
        f(i,0,n) cin>>a[i];
        ll neg = 0,ans =0;
        f(i,0,n){
            if(a[i]>0) neg+=a[i];
            else if(a[i]<0){
                ll t = min(-1*a[i],neg);
                a[i]+=t;neg-=t;
                ans+=(-1*a[i]);
            }
        }
        cout<<ans<<endl;

    }

}