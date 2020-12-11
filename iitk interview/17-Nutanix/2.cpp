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

ll DFS(vector<vector<ll>> &roads,int idx,vector<bool> &visited,ll n){
    visited[idx] = true;
    ll ans = 1;
    f(i,0,roads[idx].size())
        if(!visited[roads[idx][i]])
            ans+=DFS(roads,roads[idx][i],visited,n);
    return ans;
}

void solve(vector<vector<ll>> &roads, ll n, ll r, ll c){
    vector<bool> visited(n,false);
    ll num;ll cost = 0;
    f(i,0,n){
        if(!visited[i]){
            num= DFS(roads,i,visited,n);
            cost+=  min(c + (num-1)*r,num*c);
        } 
    }
    cout<<cost<<endl;
}
int main (){
    int t;
    scanf("%d",&t);
    while(t--){
        ll n,R,c,r;
        cin>>n>>R>>c>>r;
        vector<vector<ll>> roads(n,vector<ll>());
        f(i,0,R){
            ll a,b;
            scanf("%lld%lld",&a,&b);
            roads[a-1].pb(b-1);
            roads[b-1].pb(a-1);
        }

        solve(roads,n,r,c);


    }

}