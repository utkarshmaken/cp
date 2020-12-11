//TRAVEL AGENT
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
#define mp make_pair
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
#define endl '\n'
using namespace std;
const int mod = 1000000007;
const int maxn = 100001;

int main(){
    int n,m;cin>>n>>m;
    vector<pii> arr(n);
    f(i,0,n) cin>>arr[i].fi>>arr[i].se;
    vector<pii> package(m);
    f(i,0,m) cin>>package[i].fi>>package[i].se;
    int ans = 0;
    vector<bool> taken(n,false);
    sort(all(package));sort(all(arr));
    for(int i = 0;i<m;++i){
        int day = package[i].fi,cost = package[i].se;
        auto it = upper_bound(all(arr),mp(day,INT_MIN));
        if(it!=arr.begin()){
            --it;
            int j = it-arr.begin();int jin = j;
            while(j>=0 && (arr[j].se<cost || taken[j])) --j;
            if(j>=0){
                taken[j] = true;
                ++ans;
            }
        }
    }
    cout<<ans<<endl;
}