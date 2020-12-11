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
const int maxn = 2000000;
int suff(int suff, int val){
    int sum = 0;
    repd(i,suff,suff-val+1)
        sum+=i;
    return sum;
}
int main(){
    ll n,x;
    cin>>n>>x;
    vector<int> d(2*n);
    f(i,0,n){
        cin>>d[i];
        d[n+i] = d[i];
    }
    vector<ll>  dsum(2*n + 1);
    rep(i,1,2*n)
        dsum[i] = dsum[i-1] + d[i-1];
    ll maxi = 0;

    f(i,1,2*n){
        int s = dsum[i];
        auto it = upper_bound(all(dsum),x+s);
        if(it == dsum.end())
            continue;
        else{
            int j = (it - dsum.begin()) - 1;
            ll hugs = dsum[j] - dsum[i];
            hugs+= suff(d[i-1],x-hugs);
            maxi = max(maxi,hugs); 
        }

    }
    cout<<maxi<<endl;



}