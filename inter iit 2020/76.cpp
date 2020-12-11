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
const int maxn = 1e5;

int main(){
    string s;cin>>s;
    int k;cin>>k;
    vector<int> spec(26);
    f(i,0,26) cin>>spec[i];
    int start = 0,count = 0, n = sz(s);
    int ans = 0;
    f(i,0,n){
        if(spec[s[i]-'a'] == 0) ++count;
        while(count > k){
            if(spec[s[start]-'a'] == 0) --count;
            ++start;
        }
        ans = max(ans, i-start+1);
    }
    cout<<ans<<endl;
}

