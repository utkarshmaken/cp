//BUYING PENS WITH A DELIVERY CHARGE
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
    int n,s;
    cin>>n>>s;
    vector<vector<int>> shops(s+1,vector<int>(3));
    rep(i,1,s) cin>>shops[i][0]>>shops[i][1]>>shops[i][2];
    
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    rep(i,1,s){
        pq.push({shops[i][1] + shops[i][2],-1*i});
        --shops[i][0];
    }
    int ans = 0;
    while(n!=0){
        pii p = pq.top();
        pq.pop();
        if(p.se < 0){
            ans+=p.fi;
            n--;
            pq.push({shops[-1*p.se][1],-1*p.se});
        }
        else{
            ans+=(p.fi*min(n,shops[p.se][0]));
            n-=min(n,shops[p.se][0]);
        }
    }
    cout<<ans<<endl;


}