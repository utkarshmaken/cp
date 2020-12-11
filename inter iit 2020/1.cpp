//NO OF STARS B/W. 2 BARS OF A STRING
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
    string s;
    cin>>s;
    int q;
    cin>>q;
    vector<pii> query(q);
    f(i,0,q) cin>>query[i].fi;
    f(i,0,q) cin>>query[i].se;
    int n = s.size();
    vector<int> pos,num(n+1);
    f(i,0,n){
        num[i+1] = num[i];
        if(s[i]=='|'){
            pos.pb(i);
            num[i+1]+=1;
        }
    }

    f(i,0,q){
        int l = query[i].fi,r = query[i].se;
        --l;--r;
        int start,end;
        auto it1 = lower_bound(all(pos),l);
        auto it2 = upper_bound(all(pos),r);
        if(it1==pos.end()){
            cout<<0<<endl;
            continue;
        }
        start = *it1;
        end = *(--it2);
        int ans = (end - start + 1) - (num[end+1] - num[start]);
        cout<<ans<<endl;
    }
}