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
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<ll> miners(n), diam(n);
        int c1 = 0, c2 = 0;
        f(i,0,2*n){
            int x,y;
            cin>>x>>y;
            if(x == 0) miners[c1++] = abs(y);
            else diam[c2++] = abs(x);
        }
        sort(all(miners));
        sort(all(diam));
        ld ans = 0, c = 1;
        f(i,0,n) ans += sqrt(c*(miners[i]*miners[i] + diam[i]*diam[i]));
        printf("%0.10Le\n",ans);
    }

}