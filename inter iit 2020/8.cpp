//SHORTEST PATH IN n-ARY TREE
#include <bits/stdc++.h>
typedef long long ll;

#define pb push_back
#define all(x) x.begin(),x.end()
#define endl '\n'
using namespace std;

const int mod = 1000000007;
const int maxn = 2e5;

int main(){
    int n;cin>>n;
    ll x,y;
    cin>>x>>y;
    vector<ll> num;
    num.pb(1);
    int power = 1;
    while(num.back() < 1e12){
        ll x = num.back();
        ll add = pow(n,power);
        num.pb(x + add);
        ++power;
    }
    if(x>y) swap(x,y);
    auto it = lower_bound(all(num),x);
    int lx = it - num.begin();
    it = lower_bound(all(num),y);
    int ly = it - num.begin();
    ll ans = 0;
    while(ly>lx){
        y = (y+1)/n;
        ++ans;
        it = lower_bound(all(num),y);
        ly = it - num.begin();
    }
    while(x!=y){
        y = (y+1)/n;
        x = (x+1)/n;
        ans+=2;
    }
    cout<<ans<<endl;

}