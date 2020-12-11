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

int find(string s, int n){
    if(n<=1) return 0;

    vector<pii> occur(26,{-1,-1});
    f(i,0,n){
        if(occur[s[i]-'a'].fi == -1) occur[s[i]-'a'].fi = i;
        else occur[s[i]-'a'].se = i;
    }
    int ans = INT_MAX;
    f(i,0,26){
        if(occur[i].fi==-1 || occur[i].se==-1) continue;
        int poss  = occur[i].fi + n - occur[i].se-1;
        string str = s.substr(0,occur[i].fi) + s.substr(occur[i].fi+1,occur[i].se-1-occur[i].fi) + s.substr(occur[i].se+1);
        poss+=find(str,n-2);
        ans = min(ans,poss);
    }
    return ans;

}
int main(){
    string s;
    cin>>s;
    vector<int> freq(26);
    f(i,0,sz(s)) freq[s[i]-'a']++;
    int cnt = 0;
    f(i,0,26) if(freq[i]&1) cnt++;
    if(cnt>1)
        printf("%d\n",-1);
    else 
        printf("%d\n",find(s,sz(s)));
}