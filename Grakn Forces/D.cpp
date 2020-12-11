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
 vector<pii> ans[2000];
int ansq = INT_MAX;
void find(int idx, int n, int maxix, int maxiy){
    if(idx==n)
        ansq = min(ansq,maxix+maxiy);
    for(auto &v:ans[idx])
        find(idx+1,n,max(maxix,v.fi),max(maxiy,v.se));
    
}
int main(){
    int n,m;cin>>n>>m;
    vector<pii> rob(n),ser(m);
    f(i,0,n) cin>>rob[i].fi>>rob[i].se;
    f(i,0,m) cin>>ser[i].fi>>ser[i].se;
    vector<int> adj[n];
   
    int maxix = 0,maxiy = 0;
    f(i,0,n){
        vector<pii> dom;
        f(j,0,m){
            if(ser[j].fi>=rob[i].fi && ser[j].se>=rob[i].se)
                dom.pb({ser[j].fi,ser[j].se});
        }
        sort(all(dom));
        vector<pii> dom_f;
        int len = sz(dom),ymax = dom.back().se;
        dom_f.pb(dom.back());
        repd(j,len-2,0){
            if(dom[j].se>=ymax) dom_f.pb(dom[j]);
            ymax = max(ymax,dom[j].se);
        }
        int moves,x,y;
        sort(all(dom_f));
        len = sz(dom_f);
        moves = dom_f.back().fi - rob[i].fi + 1;
        ymax = dom_f.back().se;
        repd(j,len-2,0){
            if(dom_f[j].fi-rob[i].fi + ymax-rob[i].se+2<moves){
                moves = dom_f[j].fi-rob[i].fi + ymax-rob[i].se+2;
            }
            ymax = max(ymax,dom_f[j].se);
        }
        if(ymax-rob[i].se+1<moves)
            moves = ymax-rob[i].se+1;
        

        if(dom_f.back().fi - rob[i].fi + 1==moves) 
            ans[i].pb({dom_f.back().fi - rob[i].fi + 1,0});
        ymax = dom_f.back().se;
        repd(j,len-2,0){
            if(dom_f[j].fi-rob[i].fi + ymax-rob[i].se+2==moves){
                x = dom_f[j].fi-rob[i].fi+1;
                y = ymax-rob[i].se+1;
                ans[i].pb({x,y});
            }
            ymax = max(ymax,dom_f[j].se);
        }
        if(ymax-rob[i].se+1==moves){
            x = 0;
            y = ymax-rob[i].se+1;
            ans[i].pb({x,y});
        }
    }
    find(0,n,0,0);
    cout<<ansq<<endl;


}