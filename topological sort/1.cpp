//https://www.spoj.com/problems/TOPOSORT/
#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
bool hasCycle = false;
void dfs(vector<int> adj[], vector<int> &visited, int u){
	if(visited[u] == 2)
		return;
	if(visited[u] == 1){
		hasCycle = true;
		return;
	}
	visited[u] = 1;
	for(auto v:adj[u]){
		dfs(adj,visited,v);
		if(hasCycle) return;
	}
	ans.push_back(u);
	visited[u] = 2;
}

int main() {
	int n,m;
	cin>>n>>m;
	vector<int> adj[n];
	for(int i = 0;i<m;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
	}
	for(int i = 0;i<n;i++)
		sort(adj[i].begin(),adj[i].end(),greater<int>());
	vector<int> visited(n,0);
	for(int i = n-1;i>=0;i--){
		if(!visited[i])
			dfs(adj,visited,i);
		if(hasCycle){
			cout<<"Sandro fails."<< endl;
			return 0;
		}
	}
	reverse(ans.begin(),ans.end());
    for(auto x:ans)
        cout<<x+1<<' ';
	
	return 0;
}