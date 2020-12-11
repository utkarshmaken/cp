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
const int maxn = 2e5;

int main(){
    int n,money,rec,perk;
    cin>>n>>money>>rec>>perk;
    if(money/perk >= n)
        cout<<n<<endl;
    else{
        ll a = (n*perk - money)/(rec + perk);
        ll a1 = 0,a2 = 0,a3 = 0;
        a1 = min(n-a,(a*rec + money)/perk);
        if(a!=0) a2 = min(n-(a-1),((a-1)*rec + money)/perk);
        if(a!=n) a3 = min(n-(a+1),((a+1)*rec + money)/perk);
        cout<<max({a1,a2,a3})<<endl;
    }    


}