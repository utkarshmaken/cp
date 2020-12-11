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
    int t;
    cin>>t;
    while(t--){
        int n,a,b,da,db;
        cin>>n>>a>>b>>da>>db;
        --a;--b;
        vector<int> adj[n];
        f(i,0,n-1){
            int u,v;cin>>u>>v;
            --u;--v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        if(db<da){
            cout<<"Alice"<<endl;
            continue;
        }
        queue<int> q;
        vector<bool> visited(n);
        q.push(a);bool flag = false;
        int steps = 0;
        while(!q.empty()){
            for(int i = q.size();i>0;--i){
                int u = q.front();
                if(u==b) {flag = true;break;}
                q.pop();
                if(visited[u]) continue;
                visited[u] = true;
                for(auto v:adj[u])
                    if(!visited[v])
                        q.push(v);
            }
            if(flag) break;
            ++steps;
        }
        if(steps<da){
            cout<<"Alice"<<endl;
            continue;
        }
        if(min(db,steps) - (steps%da==0?da:steps%da) > da)
            cout<<"Bob"<<endl;
        else
            cout<<"Alice"<<endl;

    }
}