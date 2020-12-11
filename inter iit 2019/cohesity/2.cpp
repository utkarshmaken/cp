//MINIMUM HAMMING DISTANCE
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
    vector<int> parent,rank;
    UnionFind(int n){
        rank = vector<int>(n,1);
        parent.resize(n);
        for(int i = 0;i<n;i++) parent[i] = i;
    }
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        if(rank[px] > rank[py])
            parent[py] = px;
        
        else if(rank[py] > rank[px])
            parent[px] = py;

        else{
            parent[py] = px;
            ++rank[px];
        }
    }
};
int main(){
    int n;cin>>n;
    vector<int> a(n),b(n);
    f(i,0,n) cin>>a[i];
    f(i,0,n) cin>>b[i];
    int m;cin>>m;
    vector<pii> s(m);
    f(i,0,m){
        int i1,i2;
        cin>>i1>>i2;
        s[i] = {i1,i2};
    }
    UnionFind un(n);
    f(i,0,m) un.Union(s[i].fi,s[i].se);
    map<int,vector<int>> comp;
    f(i,0,n) comp[un.find(i)].push_back(i);
    int ans = 0;
    for(auto it:comp){
        vector<int> v = it.se;
        map<int,int> temp;
        for(auto &x:v){
            --temp[a[x]];
            ++temp[b[x]];
        }
        for(auto it:temp) ans+=abs(it.se);
    }
    cout<<ans/2<<endl;
}