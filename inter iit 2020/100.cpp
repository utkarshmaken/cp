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
const ll mod = 1000000007;
const int maxn = 1e5;

int main(){
    int k;cin>>k;
    int n;cin>>n;
    vector<pii> arr(n);
    f(i,0,n) cin>>arr[i].fi;
    cin>>n;
    f(i,0,n) cin>>arr[i].se;
    sort(all(arr));

    vector<int> tload(k,0);
    set<int>free;
    set<pii> busy;
    f(i,0,k) free.insert(i);
    int prev = -1;
    f(i,0,n){
        int st = arr[i].fi, load = arr[i].se;
        for(auto it:busy){
            if(it.fi <= st){
                free.insert(it.se);
                busy.erase(it);
            }
            else
                break;
        }
        if(free.empty()) continue;
        int idx;
        auto it = free.upper_bound(prev);
        if(it!=free.end())
            idx = *it;
        else
            idx = *free.begin();
        
        tload[idx]+=load;
        busy.insert({st+load-1,idx});
        free.erase(idx); 
        prev = idx;
    }
    int maxi = 0;
    f(i,0,k)
        maxi = max(maxi,tload[i]);
    
    f(i,0,k)
        if(tload[i] == maxi)
            cout<<i+1<<endl;
}