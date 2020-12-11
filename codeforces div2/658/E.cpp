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
vector<int> a,b,v;
int n;
bool solve(int i){
    if(i==-1){
        return (sz(a) == sz(b));
    }
    bool poss = false;
    if(b.empty() ||  v[i] < b.back()){
        a.pb(v[i]);
        poss = solve(i-1);
        a.pop_back();
        if(poss) return true;
    }
    if(a.empty() || v[i]< a.back()){
        b.pb(v[i]);
        poss = solve(i-1);
        b.pop_back();
    }
    return poss;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int x;
        f(i,0,2*n){
            cin>>x;
            v.pb(x);
        }
        a.pb(v[2*n-1]);
        bool ans = solve(2*n-2);
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
       
        v.clear();a.clear();b.clear();

    }

}