//CARTRIDGE RECYCLING
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
    int c,d,ce,pc;
    cin>>c>>d>>ce>>pc;
    if(d/pc >= c)
        cout<<c<<endl;
    else{
        int t = (c*pc-d)/(pc+ce);
        int ans = max( min(c-t,(d+t*ce)/pc), min(c-t-1,(d+(t-1)*ce)/pc));
        cout<<ans<<endl;
    }


}