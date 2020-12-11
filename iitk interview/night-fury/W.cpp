//WINNING POWER
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
class UnionFind{
public:
    vector<int> parent,strength;
    UnionFind(vector<int> &arr, int n){
        parent.resize(n);strength.resize(n);
        for(int i = 0;i<n;i++){
            parent[i] = i;
            strength[i] = arr[i];
        }
    }
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        if(strength[px] >= strength[py]){
            parent[py] = px;
            strength[px]+=strength[py];
        }
        else{
            parent[px] = py;
            strength[py]+=strength[px];
        }
    }


};
int main(){
    int n,m;
    cin>>n>>m;
    vector<pii> edges(m);
    f(i,0,m) cin>>edges[i].fi>>edges[i].se;
    vector<int> arr(n);
    f(i,0,n) cin>>arr[i];
    UnionFind un(arr,n);
    f(i,0,m){
        int u = edges[i].fi,v = edges[i].se;
        --u;--v;
        un.Union(u,v);
    }
    int ans = 0;
    f(i,0,n) ans = max(ans,un.strength[un.find(i)]);
    cout<<ans<<endl;

}