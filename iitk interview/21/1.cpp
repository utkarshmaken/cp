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
    
        int n;
        cin>>n;
        vector<int> v(n);
        f(i,0,n) cin>>v[i];
        sort(all(v));
        vector<int> freq;
        int count = 0;
        f(i,0,n){
            if(i>0 && v[i]!=v[i-1]){
                freq.pb(count);
                count = 1;
            }
            else
            {
                count++;
            }
        }
        freq.pb(count);
        sort(all(freq),greater<int>());
        int req = ceil(1.0*n/2);
        int ans = 0,idx = 0;
        while(req>0){
            req-=freq[idx++];
            ans++;
        }
        cout<<ans<<endl;
    

}