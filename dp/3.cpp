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
const int maxn = 200000;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    string s;cin>>s;
    vector<int> adj[n];
    f(i,0,m){
        int a,b;
        cin>>a>>b;
        --a;--b;
        adj[a].pb(b);
    }
    //if cycle is present output -1
    vector<bool> visited(n);
    vector<bool> recStack(n);
    f(i,0,n){
        if(!visited[i] && checkCycle(adj,i,visited,recStack)){
            cout<<-1<<endl;
            return 0;
        }
    }
    //if not then 
    








}