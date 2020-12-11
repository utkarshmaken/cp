// 0/1 TREE
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
vector<int> a;
int ans = 0;
void dfs(int u, int pu, int val, int level){
    if(pu == -1){
        for(auto v:adj[u])
            dfs(v,u,val,level+1);
    }
    else{
        if(a[u] == abs(val-1)){
            ans+=level;
            return;
        }
        for(auto v:adj[u])
            if(v!=pu)
                dfs(v,u,val,level+1);
    }
}
int main(){
    int n;cin>>n;
    for(int i = 0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    a.resize(n);
    for(int i = 0;i<n;i++) cin>>a[i];
    for(int i = 0;i<n;i++){
        dfs(i,-1,a[i],0);
        cout<<ans<<' ';
        ans = 0;
    }
}