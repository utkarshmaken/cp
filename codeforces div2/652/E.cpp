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
#define mp make_pair
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
using namespace std;
const int mod = 1000000007;

int main(){
        int n,m;
        cin>>n>>m;
        vector<int> w(n);
        f(i,0,n) cin>>w[i];
        vector<vector<pii>> e(n);
        vector<int> s(n);
        f(i,0,m){
            int a,b;
            cin>>a>>b;
            s[a-1]++;e[a-1].pb({i,b-1});
            s[b-1]++;e[b-1].pb({i,a-1});
        }

        queue<int> q;
        stack<int> ans;
        vector<int> visited(m,0);
        f(i,0,n)
            if(s[i]<=w[i])
                q.push(i);

        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto x:e[front]){
                if(visited[x.fi])
                    continue;
                visited[x.fi] = 1;
                ans.push(x.fi+1);
                s[x.se]--;
                if(s[x.se] == w[x.se])
                    q.push(x.se);
            }
        }
        if(ans.size() < m)
            cout<<"DEAD"<<endl;
        else{
            cout<<"ALIVE"<<endl;
            while(!ans.empty()){
                cout<<ans.top()<<' ';
                ans.pop();
            }
        }
}