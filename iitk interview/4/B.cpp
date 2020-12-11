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
int gcd(int x, int y){
    if(x<y) swap(x,y);
    while(y>=1){
        x = x%y;
        swap(x,y);
    }
    if(y==1) return 1;
    else return x;
}
int main(){
    int n;cin>>n;
    int g;cin>>g;
    int q;cin>>q;
    vector<int> xx(q),yy(q);
    f(i,0,q) cin>>xx[i];
    cin>>q;
    f(i,0,q) cin>>yy[i];
    f(i,0,q){
        int x = xx[i],y = yy[i];
        if(gcd(x,y)>g) cout<<1<<endl;
        else cout<<0<<endl;
    }

}