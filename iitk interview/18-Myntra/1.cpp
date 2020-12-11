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
using namespace std;
const int mod = 1000000007;
const int maxn = 100000;
vector<int> adj[maxn];
vector<int> val(maxn);
bool find(int u,int pu){
    for(auto v:adj[u]){
        if(v!=pu){
            if(val[v]>val[u])
                return false;
            else{
                bool ans = find(v,u);
                if(!ans)
                    return false;
            }
            
        }
    }
    return true;
}
int main(){
    int v,e;
    cin>>v>>e;
    f(i,0,e){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cin>>v;
    f(i,0,v) cin>>val[i];
    int maxi = INT_MIN;
    f(i,0,v)
        if(val[i]>maxi)
            maxi = val[i];
    int ans = 0;int index = -1;
    f(i,0,v)
        if(val[i] == maxi){
            ans++;
            index = i;
        }
   
      
    if(!find(index,-1))
        ans = 0;
    cout<<ans<<endl;
        



}