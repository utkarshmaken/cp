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
int sumDigits(int n){
    int sum = 0;
    while(n!=0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main (){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pii> v(n);
        f(i,0,n) cin>>v[i].fi>>v[i].se;
        int chef = 0,morty = 0;
        f(i,0,n){
            int a  = sumDigits(v[i].fi);
            int b  = sumDigits(v[i].se);
            if(a>=b)
                chef+=1;
            if(b>=a)
                morty+=1;
        }

        if(chef > morty)
            cout<<0<<' '<<chef<<endl;
        else if(morty>chef)
            cout<<1<<' '<<morty<<endl;
        else
            cout<<2<<' '<<chef<<endl;
    }

}