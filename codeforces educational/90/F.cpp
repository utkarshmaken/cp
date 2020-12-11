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
#define endl '\n'
using namespace std;
const int mod = 1000000007;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        f(i,0,n) cin>>a[i];
        vector<int> b(n);
        f(i,0,n) cin>>b[i];
        vector<ll> asum(n),bsum(n);
        asum[0] = a[0];bsum[0] = b[0];
        f(i,1,n){
            asum[i] = asum[i-1] + a[i];
            bsum[i] = bsum[i-1] + b[i];
        }
        if(bsum[n-1]<asum[n-1])
            cout<<"NO"<<endl;
        else{
            bool flag = true;
            ll tlow = 0,thigh = b[n-1];
            f(i,0,n-1){
               tlow = max(tlow,asum[i]-bsum[i]);
               thigh = min(thigh,asum[i]-bsum[i]+b[i]);
               if(tlow>thigh){
                   cout<<"NO"<<endl;
                   flag = false;
                   break;
               }
            }
            if(flag)
                cout<<"YES"<<endl;
        } 
    }
}
