//https://leetcode.com/discuss/interview-question/356378/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    set<int> adj[n+1];
    for(int i = 0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    if(n==2){
        cout<<1<<endl;
        return 0;
    }
    queue<int> q;vector<bool> visited(n);
    for(int i = 1;i<=n;i++){
        if(adj[i].size()==1)
            q.push(i);
    }
    int dist = 0;
    q.push(INT_MAX);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u==INT_MAX){
            dist++;
            if(q.empty()) break;
            q.push(INT_MAX);
            continue;
        }
        
        if(adj[u].empty()) break;
        int v = *adj[u].begin();
        adj[v].erase(u);
        if(adj[v].size()==1)
            q.push(v);
        else if(adj[v].empty()){
            dist++;
            break;
        }
    }
    cout<<dist<<endl;

}