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
    int t;
    cin>>t;
    while(t--){
        int x1,y1,z1,x2,y2,z2;
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        ll ans = 0;
        int tw = min(z1,y2);
        ans+=2*tw;
        z1-=tw;y2-=tw;
        if(z1 > 0){
            int two = min(z1,z2);
            z1-two;z2-=two;
            if(z2>0){
                int zer = min(x1,z2);
                x1-=zer;z2-=zer;
                if(z2>0) ans+=(-2*z2);
            }
            
        }
        else{
            int on = min(y1,y2);
            y1-=on;y2-=on;
            if(y1>0){
                int zer = min(y1,x2);
                y1-=zer;x2-=zer;
                if(y1>0) ans+=(-2*y1);
            }
        }
        cout<<ans<<endl;
    }
}