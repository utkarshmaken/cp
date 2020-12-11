//BUILD DICTIONARY
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
    int n;cin>>n;
    vector<string> arr(n);
    f(i,0,n) cin>>arr[i];
    unordered_set<string> s;
    for(auto &x:arr) s.insert(x);
    int ans = 0;
    for(auto &x:arr){
        f(i,1,sz(x)-1){
            string s1 = x.substr(0,i);
            string s2 = x.substr(i);
            if(s1!=s2 && s.find(s1)!=s.end() && s.find(s2)!=s.end())
                ++ans;
        }
    }
    cout<<ans<<endl;
}