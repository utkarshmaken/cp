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
const int maxn = 100001;
int main(){
    string s;
    cin>>s;
    vector<string> good;
    int i =0,n = sz(s);
    int cnt = 0;
    f(j,0,n){
        if(s[i]=='1') ++cnt;
        else --cnt;

        if(cnt==0){
            good.pb(s.substr(i,j-i+1));
            i = j+1;
        }
    }
    sort(all(good),greater<string>());
    string ans = "";
    for(auto &s:good) ans+=s;
    cout<<ans<<endl;
}