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
       string s;
       cin>>s;
       int zero = 0,one = 0;
       f(i,0,sz(s)){
           if(s[i]=='0')
            zero++;
           else
            one++;
       }
       int x = min(zero,one);
       if(x%2)
        cout<<"DA"<<endl;
       else
        cout<<"NET"<<endl;
       
        
    }
}
