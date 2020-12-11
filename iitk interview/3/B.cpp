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
    int n;cin>>n;
    int s0;cin>>s0;
    int k,b,m;cin>>k>>b>>m;
    ll a;cin>>a;
    k = k%m;b = b%m;
    vector<ll> s(n);s[0] = s0;
    rep(i,1,n-1) s[i] = 1 + s[i-1] + (k*s[i-1] + b)%m;
    ll ans = 0;
    int i = 0;
    while(i<n && s[i]*s[i]<=a) i++;
    ans+=i*i;
    int start = 0,end = n-1;
    while(start<i && end>=i){
        if(s[start]*s[end]<=a){
            ans+=2*(end-i+1);
            start++;
        }
        else
            end--; 
    }
    cout<<ans<<endl;
}