//ALIEN DICTIONARY
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
    vector<string> word(n);
    f(i,0,n) cin>>word[i];
    vector<int> adj[26];
    f(i,0,n-1){
        int j = 0;
        int l1 = word[i].size(),l2 = word[i+1].size();
        while(j<min(l1,l2) && word[i][j] == word[i+1][j]) j++;
        if(j==min(l1,l2)) continue;
        int u = word[i][j] - 'a';
        int v = word[i+1][j] - 'a';
        adj[u].pb(v);
    }
    vector<int> indegree(26);
    f(i,0,26)
        for(auto v:adj[i])
            ++indegree[v];
    queue<int> q;
    vector<char> ans;
    f(i,0,26)
        if(indegree[i] == 0)
            q.push(i);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.pb('a' + u);
        for(auto v:adj[u]){
            --indegree[v];
            if(indegree[v] == 0)
                q.push(v);
        }
    }
    for(auto &x:ans) cout<<x<<' ';
    cout<<endl;
}