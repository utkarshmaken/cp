//INTERVAL DEADLINE MAX MEETINGS
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
bool compare(pii &a, pii &b){
    if(a.fi == b.fi)
        return a.se < b.se;
    return a.fi < b.fi;
}
int main(){
    int n;cin>>n;
    vector<pii> arr(n);
    f(i,0,n) cin>>arr[i].fi>>arr[i].se;
    sort(all(arr),compare);
    int ans = 0;
    priority_queue<int,vector<int>,greater<int> > pq;
    int i = 0,t;
    while(i<n || !pq.empty()){
        if(pq.empty()) t = arr[i].fi;
        while(!pq.empty() && pq.top() < t) pq.pop();
        while(i<n && arr[i].fi==t) pq.push(arr[i++].se);
        if(!pq.empty()){
            pq.pop();
            ++ans;
            ++t;
        }
    }
    cout<<ans<<endl;

}