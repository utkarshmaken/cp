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
    int ans = 0,poss = -1;
    repd(i,8,0){
        if(sets[i]){
            
            if(poss==-1 && adj[i].empty()){
                ans+=(1<<i);
            }
            else if(poss==-1){
                poss = i;
            }
            else if(poss!=-1){
                set<int> s;
                for(auto x:adj[poss])
                    if(adj[i].find(x)!=adj[i].end())
                        s.insert(x);
                if(s.empty())
                    ans+=(1<<i);
                else
                    adj[poss] = s;
            }
        }
        cout<<ans<<endl;
    }
    cout<<ans<<endl;

}