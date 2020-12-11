//AVOID SARS-CoV-2
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

int main(){
    int n;
    cin>>n;
    vector<pii> adj[n];
    string s;
    cin>>s;

    int pos = s.find(']'), curr = 1, len = s.size();
    while(pos<len){
        string t = s.substr(curr,pos-curr);
        t+=",";
        string num = "";
        int arr[3];int idx =0;
        f(i,0,sz(t)){
            if(t[i]!=',') num+=t[i];
            else{
                arr[idx++] = stoi(num);
                num = "";
            }
        }
        int u = arr[0],v = arr[1],w = arr[2];
        adj[u].pb({v,w});
        pos+=2;curr = pos+1;
        if(pos>len) break;
        pos = s.find(']',pos);
    }

    int start,dest;
    cin>>start>>dest;
    int k;cin>>k;
    k++;
    vector<int> dist(n,INT_MAX);
    vector<vector<bool>> visited(n,vector<bool>(k+1));
    priority_queue<vector<int> ,vector<vector<int>>, greater<vector<int>> > pq;
    pq.push({0,start,k});dist[start] = 0;
    while(!pq.empty()){
        int d = pq.top()[0], u = pq.top()[1],krem = pq.top()[2];
        pq.pop();
        if(visited[u][krem])
            continue;
        visited[u][krem] = true;
        for(auto &p:adj[u]){
            if(dist[p.fi] > d + p.se)
                dist[p.fi] = d+p.se;
            if(krem!=0) pq.push({d+p.se,krem-1});
        }
    }
    if(dist[dest]!=INT_MAX)
        cout<<dist[dest]<<endl;
    else
        cout<<-1<<endl;
}