//COMICS DEBACLE
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
    int t;
    cin>>t;
    while(t--){
        int x,y,z,k;
        cin>>x>>y>>z>>k;
        vector<int> time(y);
        f(i,0,y) cin>>time[i];
        sort(all(time));
        int ans = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>> > pq;
        priority_queue<int,vector<int>,greater<int> > bq;
        f(i,0,y) pq.push({time[i],0,i,0});
        f(i,0,z) bq.push(0);
        rep(i,1,x){
            vector<int> v = pq.top();
            pq.pop();
            int t0 = v[0],avail = v[1],idx = v[2],state = v[3];
            pq.push({avail+2*time[idx],avail+time[idx],idx,1});
            if(state == 1){
                int bind = bq.top();
                bq.pop();
                bq.push(max(avail,bind) + k);
            }
        }
        while(!pq.empty()){
            vector<int> v = pq.top();
            pq.pop();
            int t0 = v[0],avail = v[1],idx = v[2],state = v[3];
            if(state == 1){
                int bind = bq.top();
                bq.pop();
                bq.push(max(avail,bind) + k);
            }
        }
        int t = 0;
        while(!bq.empty()){
            t = max(t,bq.top());
            bq.pop();
        }
        cout<<t<<endl;
    }
}