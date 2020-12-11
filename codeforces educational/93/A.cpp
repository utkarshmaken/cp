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
        vector<ll> a(n);
        f(i,0,n) cin>>a[i];
        bool flag = false;
        f(i,0,n-2)
            if(a[i] + a[i+1]<=a[n-1]){
                flag = true;
                cout<<i+1<<' '<<i+2<<' '<<n<<endl;
                break;
            }
        if(!flag) cout<<-1<<endl;

    }

}