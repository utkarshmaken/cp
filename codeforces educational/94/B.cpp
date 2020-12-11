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
       int p,f;cin>>p>>f;
       int cnt_s,cnt_w;cin>>cnt_s>>cnt_w;
       int s,w;cin>>s>>w;
       if(s>w){
           swap(s,w);
           swap(cnt_s,cnt_w);
        }
       int ans = 0;
       rep(i,0,cnt_s){
           if(i*s>p) break;
           int x1 = i;
           int rem = p-x1*s;
           int y1 = min(cnt_w,rem/w);
           int x2 = min(cnt_s-x1,f/s);
           rem = f-x2*s;
           int y2 = min(cnt_w-y1,rem/w);
           ans = max(ans,x1+y1+x2+y2);
       }
        cout<<ans<<endl;
    }
}