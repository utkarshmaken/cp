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
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x2<x1 || y2<y1){
        cout<<"No"<<endl;
        return 0;
    }
    bool flag = false;
    queue<pll> q;
    set<ll> sx;set<ll> sy;
    q.push({x2,y2});
    sx.insert(x2);sy.insert(y2);
    while(!q.empty()){
        ll x = q.front().fi,y = q.front().se;
        if(x==x1 && y==y1){
            flag = true;
            break;
        }
        q.pop();
        if(sx.find(y)!=sx.end() || sy.find(x)!=sy.end())
            continue;
        ll xf = x-y,yf = y;
        if(xf>=x1 && yf>=y1)
           q.push({xf,yf});
        
        ll xs = x,ys = y-x;
        if(xs>=x1 && ys>=y1)
            q.push({xs,ys});
        
    }
    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;


}