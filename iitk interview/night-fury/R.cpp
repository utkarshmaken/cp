//CAN YOU MAKE A PALINDROME
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
    string s;cin>>s;
    int q;cin>>q;
    vector<pii> query(q);
    vector<int> subs(q);
    f(i,0,q) cin>>query[i].fi;
    f(i,0,q) cin>>query[i].se;
    f(i,0,q) cin>>subs[i];
    int n = s.size();
    vector<int> num(n+1);
    rep(i,1,n){
        int pos = s[i-1]-'a';
        num[i] = num[i-1]^(1<<pos);
    }
    string ans = "";
    f(i,0,q){
        int l = query[i].fi,r = query[i].se;
        int parity = num[r+1]^num[l];
        int ones = 0;
        while(parity!=0){
            ones+=(parity&1);
            parity = (parity>>1);
        }
        if(ones/2<=subs[i])
            ans+='1';
        else
            ans+='0';
    }
    cout<<ans<<endl;
}