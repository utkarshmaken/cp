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
       int inv = 0;bool last = true;
       repd(i,n-1,0){
           if(!(inv&1)){
               if(last){
                   if(b[i] == a.back()){
                       a.pop_back();
                       continue;
                   }
                   if(a[0]==b[i]){
                       ans.pb(1);
                       if(a[0]=='1') a[0]='0';
                       else a[0] = '1';
                   }
                   ans.pb(i+1);
                   a.erase(a.begin());
                   last = false;inv++;
                }
                else{
                    if(b[i]==a.front()){
                         a.erase(a.begin());
                         continue;
                    }
                    if(a.back()==b[i]){
                        ans.pb(1);
                        if(a[sz(a)-1]=='1') a[sz(a)-1] = '0';
                        else a[sz(a)-1] = '1';
                    }
                    ans.pb(i+1);
                    a.pop_back();
                    last = true;inv++;
               }
           }
           else{
               if(last){
                   if(b[i] != a.back()){
                       a.pop_back();
                       continue;
                   }
                   if(a[0]!=b[i]){
                       ans.pb(1);
                       if(a[0]=='1') a[0]='0';
                       else a[0] = '1';
                   }
                   ans.pb(i+1);
                   a.erase(a.begin());
                   last = false;inv++;
                }
                else{
                    if(b[i]!=a.front()){
                         a.erase(a.begin());
                         continue;
                    }
                    if(a.back()!=b[i]){
                        ans.pb(1);
                        if(a[sz(a)-1]=='1') a[sz(a)-1] = '0';
                        else a[sz(a)-1] = '1';
                    }
                    ans.pb(i+1);
                    a.pop_back();
                    last = true;inv++;
                }
            }
       }

       cout<<sz(ans)<<' ';
       for(auto p:ans) cout<<p<<' ';
       cout<<endl;

    }

}