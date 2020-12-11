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
#define mp make_pair
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
          f(i,0,n){
            if(!(i&1))
                a[i] = a[i]>0?-1*a[i]:a[i];
            else
                a[i] = a[i]>0?a[i]:-1*a[i];
          }

          f(i,0,n) cout<<a[i]<<' ';
          cout<<'\n';
          
    }

}