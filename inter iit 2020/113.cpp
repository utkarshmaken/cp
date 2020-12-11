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
const ll mod = 1000000007;
const int maxn = 1e5;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,s;
        cin>>n>>s;
        vector<ll> arr(n+1);
        rep(i,1,n) cin>>arr[i];
        unordered_map<int,int> m;
        m[0] = 0;
        ll curr = 0;
        int f = 0;
        rep(i,1,n){
            curr += arr[i];
            if(m.find(curr - s) != m.end()){
                cout<<m[curr-s]+1<<' '<<i<<endl;
                f = 1;
                break;
            }
            m[curr] = i;
        }
        if(!f) cout<<-1<<endl;
    }

}