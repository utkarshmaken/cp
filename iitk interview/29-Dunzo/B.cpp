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
const int maxn = 100001;
set<int> adj[26];
string ans;
void find(int u){
    char c = 'A' + u;
    ans+='(';ans+=c;
    for(int v:adj[u])
        find(v);
    ans+=')';
}
int main(){
    string s;
    getline(cin,s);
    int n = sz(s);
    vector<bool> child(26,false),nodes(26,false);
    vector<int> parent(26,-2);
    for(int i = 1;i<n;i+=6){
        int u = s[i]-'A';
        int v = s[i+2] - 'A';
        if(adj[u].find(v)!=adj[u].end()){
            cout<<"E2"<<endl;
            return 0;
        }
        if(sz(adj[u])==2){
            cout<<"E1"<<endl;
            return 0;
        }
        if(child[v]){
            cout<<"E3"<<endl;
            return 0;
        }
        adj[u].insert(v);
        parent[v] = u;
        if(parent[u]==-2) parent[u] = -1;
        child[v] = true;
        nodes[u] = true;
        nodes[v] = true;
    }
    vector<int> root;
    f(i,0,26)
        if(parent[i]==-1) root.pb(i);
    if(sz(root)>1){
        cout<<"E4"<<endl;
        return 0;
    }
    int edges = 0,node = 0;
    f(i,0,26) node+=nodes[i];
    f(i,0,26) edges+=sz(adj[i]);
    if(edges>node-1){
        cout<<"E3"<<endl;
        return 0;
    }
    if(edges<node-1){
        cout<<"E5"<<endl;
        return 0;
    }
    find(root[0]);
    cout<<ans<<endl;


}