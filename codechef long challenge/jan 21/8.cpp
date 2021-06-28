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
        ll n,m;
        cin>>n>>m;
        vector<int> a(n),b(m);
        f(i,0,n) cin>>a[i];
        f(i,0,m) cin>>b[i];
        set<int> ans;
        queue<int> q;
        q.push(0);ans.insert(0);
        while(!q.empty()){
            for(int rep = q.size(); rep > 0; --rep){
                int v = q.front();
                q.pop();
                for(auto &x:a){
                    int nv = v | x;
                    if(ans.find(nv) == ans.end()){
                        q.push(nv);
                        ans.insert(nv);
                    }
                }
                for(auto &x:b){
                    int nv = v & x;
                    if(ans.find(nv) == ans.end()){
                        q.push(nv);
                        ans.insert(nv);
                    }
                }
            }
        }
        cout<<ans.size()<<endl;
    }
}