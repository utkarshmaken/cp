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
const ll mod = 998244353;
const int maxn = 100001;

int l,r,a,b;
vector<ll> cool = {1,2,4,3,,27,81,243,729};
ll curr = 1, len = 0;
ll ans = 0;
void find(int l){
    if(l == r+1){
        if(len >= a && len <= b){
            int res = 0;
            for(auto &x:cool)
                if(curr % x == 0)
                    ++res;
            ans = (ans + res) % mod;
        }
        return;
    }
    find(l+1);
    curr *= l;++len;
    find(l+1);
    curr /= l;--len;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>l>>r>>a>>b;
        if(r-l+1 < a || r-l+1 > b){
            cout<<0<<endl;
            continue;
        }
        curr = 1;len = 0;
        find(l);
       cout<<ans<<endl;
    }
}