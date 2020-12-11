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

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(2*n);
        f(i,0,2*n) cin>>v[i];
        int idx = 0;
        unordered_map<int,int> m;
        f(i,0,2*n)
            if(m.find(v[i])==m.end())
                m[v[i]] = idx++;
            
        
        vector<pii> ans;
        for(auto it:m)
            ans.pb({it.se,it.fi});
        sort(all(ans));
        f(i,0,n) cout<<ans[i].se<<' ';
        cout<<endl;
    }

}