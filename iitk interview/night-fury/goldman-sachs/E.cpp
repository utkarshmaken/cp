//PETROL COST
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
    int n,m,s,c;
    cin>>n>>m>>s>>c;
    vector<pii> adj[n+1];
    f(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    unordered_map<int,int> fuel;
    f(i,0,s){
        int u,p;
        cin>>u>>p;
        fuel[u] = p;
    }
    int a,b;
    cin>>a>>b;
    auto compare = [&](vector<int> &a, vector<int> &b){

    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);
    








}