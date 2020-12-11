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
#define mp make_pair
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
using namespace std;
const int mod = 1000000007;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        vector<pii> arr(n);
        f(i,0,n) cin>>v[i],arr[i] = {v[i],i};
        sort(all(arr));
        f(i,0,n)
            v[arr[i].se] = i;
        unordered_map<int,int> m;
        f(i,0,n) m[v[i]] = i;
        vector<int> dp(n);
        int maxi = 0;
        f(i,0,n){
           int  num = v[i];
           if(num==0 || m[num-1] > i)
                dp[i] = 1;
           else
                dp[i] = 1 + dp[m[num-1]];
           
           maxi = max(maxi,dp[i]);
        }
        cout<<n - maxi<<endl;



        
    }

}