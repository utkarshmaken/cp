//XOR OF TWO NUMBERS
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
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    f(i,0,n) cin>>a[i];
    f(i,0,n) cin>>b[i];
    f(i,0,n){
        if(b[i] > a[i]){
            cout<<0<<endl;
            continue;
        }
        ll x = 0,y = b[i];
        ll req = a[i] - b[i];
        if(req&1){
            cout<<0<<endl;
            continue;
        }
        req = req>>1;
        bool poss = true;
        int j = 0;
        while(req!=0){
            if(req & 1){
                if((b[i]&(1<<j)) == 1){
                    poss = false;
                    break;
                }
                else{
                    x+=(1<<j);
                    y+=(1<<j);
                }
            }
            ++j;
            req = req>>1;
        }
        if(poss) cout<<2*x+3*y<<endl;
        else cout<<0<<endl;
    }
}