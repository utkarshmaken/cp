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

int main(){
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       vector<int> a(n);
       f(i,0,n) cin>>a[i];
       vector<int> dp(n);
       dp[n-1] = 1;
       repd(i,n-2,0){
            if(a[i]==1)
                dp[i] = !dp[i+1];
            else
                dp[i] = 1;
            
       }
       if(dp[0]==1)
            cout<<"First"<<endl;
        else
            cout<<"Second"<<endl;
    }

}