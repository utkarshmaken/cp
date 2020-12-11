//PAINT THE CEILING
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n,s0,k,b,m,a;
    cin>>n>>s0>>k>>b>>m>>a;
    vector<ll> side(n);
    side[0] = s0;
    for(int i = 1;i<n;i++)
        side[i] = 1 + side[i-1] + (k*side[i-1] + b)%m;
    ll ans = 0;
    ll roota = sqrt(a);
    auto it = upper_bound(side.begin(),side.end(),roota);
    if(it == side.begin()){
        cout<<0<<endl;
        return 0;
    }
    --it;
    ll idx = it - side.begin();
    ans+= (idx+1)*(idx+1);
    ll i = 0,j = n-1;
    while(j>idx && i<=idx){
        if(side[j]*side[i] <=a){
            ans+=2*(j-idx);
            i++;
        }
        else{
            j--;
        }
    }
    cout<<ans<<endl;
}