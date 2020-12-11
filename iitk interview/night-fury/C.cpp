//WINE TASTING
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
   int b,n;
   cin>>b>>n;
   vector<int> arr(b);
   f(i,0,n) cin>>arr[i];
   sort(all(arr));
   int max_count,maxi = 0,total =0;
   f(i,0,b){
       total+=arr[i];
       if(arr[i]==maxi) ++max_count;
       else if(arr[i] > maxi){
           maxi = arr[i];
           max_count = 1;
       }
   }
   int slots = (maxi-1)*(n-max_count+1);
   int filled = maxi*max_count;
   int rem = total - filled;
   if(rem <= slots) cout<<slots + filled<<endl;
   else cout<<total<<endl;

}