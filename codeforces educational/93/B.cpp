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
        string s;
        cin>>s;
        int n = sz(s);
        vector<int> ones;
        int c = 0;
        f(i,0,n){
            if(s[i]=='1') c++;
            else if(c>0){
                ones.pb(c);
                c=0;
            }
        }
        if(c>0) ones.pb(c);
        sort(all(ones));
        reverse(all(ones));
        int ans = 0;
        for(int i = 0;i<sz(ones);i+=2) ans+=ones[i];
        cout<<ans<<endl;

    }

}