//Minimum number of distinct elements after removing M items
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
    int n;cin>>n;
    vector<int> arr(n);
    f(i,0,n) cin>>arr[i];
    int m;cin>>m;
    unordered_map<int,int> freq;
    for(auto &x:arr) ++freq[x];
    vector<int> fre_arr(n+1,0);
    for(auto it:freq) ++fre_arr[it.se];
    int ans = 0;
    rep(i,1,n){
        int x = fre_arr[i];
        if(x == 0) continue;
        if(m >= x*i) m-=x*i;
        else{
            int rem = x - m/i;
            m -= (m/i)*i;
            ans+=rem;
        }
    }
    cout<<ans<<endl;
    

    
    
}