//MINIMUM SUM
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
const int maxn = 2e5;

int main(){
    int n;cin>>n;
    vector<int> a(n);
    f(i,0,n) cin>>a[i];
    int k;cin>>k;
    multiset<int> s;
    f(i,0,n) s.insert(a[i]);
    f(i,0,k){
        int x = *(--s.end());
        s.erase(--s.end());
        s.insert((x+1)/2);
    }
    int ans = 0;
    for(auto x:s) ans+=x;
    cout<<ans<<endl;




}