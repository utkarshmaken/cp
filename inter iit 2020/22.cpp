//RANDOM NUMBER GENERATOR
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    ll ans = 0;
    int mod = pow(10,9) + 7;
    for(int i = 0;i<k;i++){
        ans = (ans+n-i)%mod;
    }
    cout<<ans<<endl;
}
