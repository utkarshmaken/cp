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
const int maxn = 2000000;
vector<int> ans;
bool hasCycle = false;
void dfs(vector<int> adj[], vector<int> &color, int u){
    if(color[u]==2)
        return;
    if(color[u]==1){
        hasCycle = true;
        return;
    }
    color[u] = 1;
    for(auto v:adj[u]){
        dfs(adj,color,v);
        if(hasCycle) return;
    }
    ans.pb(u);
    color[u] = 2;
}

int main(){
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i = 0;i<n;i++)
        cin>>s[i];
    vector<int> adj[26];
    for(int i = 0;i<n-1;i++){
        int j = 0;
        while(j<min(sz(s[i]),sz(s[i+1])) && s[i][j] == s[i+1][j])
            j++;
        if(j==min(sz(s[i]),sz(s[i+1]))){
            if(sz(s[i]) > sz(s[i+1])){
                cout<<"Impossible"<<endl;
                return 0;
            }
            continue;
        }
            
        adj[s[i][j] - 'a'].pb(s[i+1][j] - 'a');
    }

    vector<int> color(26,0);
    for(int i = 0;i<26;i++){
        if(!color[i])
            dfs(adj,color,i);
        if(hasCycle){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    reverse(all(ans));
    for(auto x:ans)
        cout<<char(x + 'a');
    

}