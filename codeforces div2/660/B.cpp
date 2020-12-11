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
const int maxn = 200000;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string ans(n,'9');
        int rem = n/4;
        repd(i,n-1,n-rem)
            ans[i] = '8';
        if(n%4)
            ans[n-rem-1] = '8';
        cout<<ans<<endl;
    }

}