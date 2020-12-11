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
const int maxn = 300001;
int t,n,k,l;

int main(){
    vector<int> d(maxn);
    cin>>t;
    while(t--){
        cin>>n>>k>>l;
        rep(i,1,n) cin>>d[i];
        vector<int> safe;
        safe.pb(0);
        rep(i,1,n)
            if(d[i] + k<=l)
                safe.pb(i);
        safe.pb(n+1);
        bool flag = true;
        f(i,1,sz(safe)){
            int t = k;bool down = true;
            f(j,safe[i-1]+1,safe[i]){
                t+= down?-1:1;
                if(down) t-=max(0,d[j] + t - l);
                if(t<0 || d[j]+t>l){flag = false;break;}
                if(t == 0) down = false;
            }
            if(!flag) break;
        }

        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}