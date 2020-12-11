//PRIME FACTOR VISITATION
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
    int n;
    cin>>n;
    vector<int> state(n+1);
    rep(i,1,n) cin>>state[i];
    int k;cin>>k;
    vector<int> arr(k);
    f(i,0,k) cin>>arr[i];
    vector<int> nums;
    f(i,0,k){
        int a = arr[i];
        if(a%2==0){
            nums.pb(2);
            while(a%2==0) a/=2;
        }
        for(int i = 3;i*i<=a;i+=2){
            if(a%i==0){
                nums.pb(i);
                while(a%i==0) a/=i;
            }
        }
    }
    map<int,int> m;
    set<int> s;
    for(auto &x:nums) m[x]++;
    for(auto it:m)
        if(it.se&1)
            s.insert(it.fi);
    rep(i,2,n){
        int div = 0;
        for(auto x:s)
            if(i%x==0) ++div;
        if(div&1) state[i] = 1-state[i];
    }
    rep(i,1,n) cout<<state[i]<<" ";
    

}