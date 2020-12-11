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
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        int moves = 0;
        while(n!=1){
            if(n%6 == 0){
                n/=6;
                moves++;
            }
            else if(n%3 == 0){
                moves++;
                n*=2;
            }
            else{
                moves = -1;
                break;
            }
        }
        cout<<moves<<endl;
    }

}