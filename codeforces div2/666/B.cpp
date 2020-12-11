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
    int n;
    cin>>n;
    vector<ll> a(n);
    f(i,0,n) cin>>a[i];
    sort(all(a));
    if(n==2){
        cout<<a[0]-1<<endl;
        return 0;
    }
    ll mini = 0;
    f(i,0,n) mini+=abs(a[i]-1);
    ll maxi = 1e15;
    int cmax = 2;
    while(true){
        ll cc = 1;
        f(i,0,n){
            cc*=cmax;
            if(cc>maxi)
                break;
        }
        if(cc>maxi) break;
        else cmax++;
    }
   
    for(ll c = 2;c<=cmax;++c){
        ll poss = 0,cc = 1;
        f(i,0,n){
            poss+=max(cc-a[i],a[i]-cc);
            cc*=c;
            if(cc>1e15){poss = 1e18;break;}
        }
        mini = min(mini,poss);
    }
    cout<<mini<<endl;

}