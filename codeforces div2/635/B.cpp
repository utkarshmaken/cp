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
const int maxn = 2000000;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,n,m;
        cin>>x>>n>>m;
        while(x>20 && n){
            x = x/2 + 10;
            n--;
        }
        while(m){
            x = x-10;
            m--;
        }
        if(x>0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }

}