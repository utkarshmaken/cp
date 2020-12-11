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
       string a,b;
       cin>>a>>b;
       vector<int> ans;
       int inv = 0;int zero = 0,last = n-1;
       repd(i,n-1,0){
           if((!(inv&1) && a[last] == b[i]) || ((inv&1) && a[last]!=b[i])){
               if(last>zero) --last;
               else ++last;
               continue;
           }
           if((!(inv&1) && a[zero] == b[i]) || ((inv&1) && a[zero] != b[i])){
                ans.pb(1);
                if(a[zero]=='1') a[zero]='0';
                else a[zero] = '1';
           }
           ans.pb(i+1);
           swap(last,zero);
           if(last<zero){
               last++; 
                zero--;
            }
            else{
                last--;
                zero++;
            }
            inv++;
       }

       cout<<sz(ans)<<' ';
       for(auto p:ans) cout<<p<<' ';
       cout<<endl;

    }

}