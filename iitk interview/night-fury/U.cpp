//MICS
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
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    f(i,0,n) cin>>arr[i];
    multiset<int> s;
    for(auto &x:arr) s.insert(x);
    int ans = *s.rbegin();
    m-=n;
    while(m>0){
        auto it = (--s.end());
        if(*it==1) break;
        s.insert(*it/2);
        s.insert(*it/2);
        s.erase(it);
        ans = *s.rbegin();
        --m;
    }
    cout<<ans<<endl;

}