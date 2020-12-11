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
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<pii> v(4*n);
        f(i,0,4*n-1) scanf("%d%d",&v[i].fi,&v[i].se);
        map<int,vector<int>> mx;
        map<int,vector<int>> my;
        f(i,0,4*n-1){
            mx[v[i].fi].pb(v[i].se);
            my[v[i].se].pb(v[i].fi);
        }
        int x,y;
        for(auto it = mx.begin();it!=mx.end();it++)
            if(it->se.size() & 1){
                x = it->fi;
                break;
            }
        for(auto it = my.begin();it!=my.end();it++)
            if(it->se.size() & 1){
                y = it->fi;
                break;
            }
        
        cout<<x<<' '<<y<<endl;
        
    }
}