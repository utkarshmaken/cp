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
const int maxn = 200000;
void solve(){

    
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
       string s;
       cin>>s;
       int n = sz(s);
       int ans = 0;
       int i = 0;
       while(i<n-1){
           if(s[i]!=s[i+1]){
               ans++;
               i+=2;
           }
           else
           {
               i++;
           }
       }
       cout<<ans<<endl;

    }

}