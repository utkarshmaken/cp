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
   int n;
   cin>>n;
   vector<int> range(n+1);
   rep(i,1,n) cin>>range[i];
   vector<int> max_reach(n+1);
   rep(i,1,n){
       int l = max(1,i-range[i]);
       int r = min(n,i+range[i]);
       max_reach[l] = max(max_reach[l],r);
   }

   int ans = 0,reach = 1,end = 1;
   for(int i = 1;i<=n;i++){
       if(reach>=n) break;
       end = max(end,max_reach[i]);
       if(reach==i){
            reach = end;
            ans++;
        }
        
        
   }
   cout<<ans<<endl;
}