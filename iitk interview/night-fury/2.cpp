//DIVISIBILITY OF STRINGS
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
vector<int> factors(int n){
    vector<int> ans;
    int rootn = sqrt(n);
    rep(i,1,rootn){
        if(n%i==0){
            ans.pb(i);
            if(i*i!=n) ans.pb(n/i);
        }
    }
    return ans;
}
int main(){
    string s,t;
    cin>>s>>t;
    int n = sz(s),len = sz(t);
    if(n%len!=0){
        cout<<-1<<endl;
        return 0;
    }
    string temp = "";
    f(i,0,n/len) temp+=t;
    if(temp!=s){
        cout<<-1<<endl;
        return 0;
    } 
    vector<int> fac = factors(len);
    sort(all(fac));
    int ans;
    for(auto &x:fac){
        string tt = t.substr(0,x);
        string temp ="";
        f(i,0,len/x) temp+=tt;
        if(temp == t){
            ans = x;
            break;
        }
    }
    cout<<ans<<endl;
}