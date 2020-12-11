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
       int n,m;
       cin>>n>>m;
       vector<int> a(n),b(m);
       f(i,0,n) cin>>a[i];
       f(i,0,m) cin>>b[i];
       sort(all(a));sort(all(b));
       int i = 0,j = 0;
       bool flag = false;
       while(i<n && j<m){
           if(a[i]==b[j]){
               flag = true;
               cout<<"YES"<<endl;
               cout<<1<<' '<<a[i]<<endl;
               break;
           }
           else if(a[i]<b[j])
                i++;
            else
                j++;
       }
       if(!flag)
        cout<<"NO"<<endl;

    }

}