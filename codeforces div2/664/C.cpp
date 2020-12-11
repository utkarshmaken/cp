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
const int maxn = 100001;

int main(){
   int n,m;
   cin>>n>>m;
   vector<int> a(n),b(m);
   f(i,0,n) cin>>a[i];
   f(i,0,m) cin>>b[i];
   vector<bool> sets(9);
   rep(i,0,n){
       int x =a[i];
       int j = 0;
       while(x!=0){
           if(!sets[j] && (x&1))
            sets[j] = true;
           x/=2;
           j++;
        }
    }
    f(i,0,9) cout<<sets[i]<<' ';
    cout<<endl;
    set<int> adj[9];
    f(i,0,m){
        int x = b[i];
        int j = 0;
        while(j<9){
            if(!(x&1))
                adj[j].insert(i);
            x/=2;
            j++;
        }
    }
    vector<int> ans(9);
    vector<bool> done(n);
    int poss = -1;
    repd(i,8,0){
        if(sets[i]){
            if(adj[i].empty()){
                ans[i] = 1;
                continue;
            }

            if(poss==-1)
                poss = i;
            else{
                set<int> s;
                for(auto x:adj[poss])
                    if(adj[i].find(x)!=adj[i].end())
                        s.insert(x);
                if(s.empty())
                    ans[i] = 1;
                else
                    adj[poss] = s;
            }
            if(sz(adj[poss]==1)){
                

            }

        }
        cout<<ans<<endl;
    }
    cout<<ans<<endl;

}