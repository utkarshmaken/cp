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
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        map<ll,ll> zeros;
        ll ans = 0,curr = 0;
        zeros[0]++;
        f(i,0,n){
            curr+=(s[i]-'0'-1);
            ans+=zeros[curr];
            zeros[curr]++;
        }

        cout<<ans<<endl;
    }

}