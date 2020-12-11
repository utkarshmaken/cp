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
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    f(i,0,n) cin>>a[i];
    map<int,set<int>> m;
    f(i,0,n){
        int x = a[i]-1;
        m[i-x].insert(i);
    }
    f(i,0,q){
        int x,y;
        cin>>x>>y;
        int ans = 0;
        int c = 0;int l = x;int r = n-1-y;
        while(true){
            auto it = m[c].lower_bound(l);
            if(it==m[c].end() || *it>r) break;
            ++ans;++c;
        }
        cout<<ans<<endl;
    }

}