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
#define mp make_pair
#define pb push_back
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
using namespace std;
const int mod = 1000000007;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,r;
        cin>>n>>r;
        ll ans = 0;
        ll a = min(n-1,r);
        ans+= a*(a+1)/2;
        if(r>a)
            ans+=1;      
        cout<<ans<<endl;
        
    }
}