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
        int n,k;
        cin>>n>>k;
        rep(i,1,k-3) cout<<1<<' ';
        n -= (k-3);
        if(n&1)
            cout<<1<<' '<<n/2<<' '<<n/2<<endl;
        else if(n % 4 == 0)
            cout<<n/4<<' '<<n/4<<' '<<n/2<<endl;
        else
            cout<<2<<' '<<n/2-1<<' '<<n/2-1<<endl;
    }

}