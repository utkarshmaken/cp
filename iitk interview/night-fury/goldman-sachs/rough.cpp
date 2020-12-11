#include <bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;
void delete_edges(set<pii> adj[], vector<int> pred[], int d){
	if(pred[d].empty())
		return;
	for(auto &v:pred[d]){
		auto it = adj[v].lower_bound(make_pair(d,INT_MIN));
		if(it!=adj[v].end()){
            adj[v].erase(it);
	        delete_edges(adj,pred,v);
        }
	}
}
int main() {
	int n,m,s,d;
	cin>>n>>m;
    while(n*m>0){
    cin>>s>>d;
	set<pii> adj[n];
	for(int i = 0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].insert({v,w});
	}
	
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	vector<int> dist(n,INT_MAX);
	vector<int> pred(n);
	vector<bool> mark(n,false);
	pq.push({0,s});dist[s] = 0;
	while(!pq.empty()){
		int d = pq.top().fi,u = pq.top().se;
		pq.pop();
		if(mark[u])
            continue;
        
		mark[u] = true;
		for(auto &p:adj[u]){
			if(d+p.se<dist[p.fi]){
				dist[p.fi] = d + p.se;
				pred[p.fi] = u;
				pq.push({dist[p.fi],p.fi});
			}
		}
	}
    vector<int> preds[n];
    vector<int> dists(n,INT_MAX);
    mark = vector<bool>(n,false);
    pq.push({0,s});dists[s] = 0;
    while(!pq.empty()){
		int d = pq.top().fi,u = pq.top().se;
		pq.pop();
		if(mark[u])
            continue;
        
		mark[u] = true;
		for(auto &p:adj[u]){
			if(d+p.se<dists[p.fi]){
				dists[p.fi] = d + p.se;
				pq.push({dists[p.fi],p.fi});
			}
            if(d + p.se==dist[p.fi]) 
                    preds[p.fi].push_back(u);
		}
	}
   delete_edges(adj,preds,d);
	
	dist = vector<int>(n,INT_MAX);
	mark = vector<bool>(n,false);
	pq.push({0,s});dist[s] = 0;
	while(!pq.empty()){
		int d = pq.top().fi,u = pq.top().se;
		pq.pop();
		if(mark[u])
			continue;
		mark[u] = true;
		for(auto &p:adj[u]){
			if(d+p.se<dist[p.fi]){
				dist[p.fi] = d + p.se;
				pq.push({dist[p.fi],p.fi});
			}
			
		}
	}
	cout<<(dist[d]==INT_MAX?-1:dist[d])<<endl;
    cin>>n>>m;
    }
}