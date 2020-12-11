//PROCESS SCHEDULER
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
 
int main(){
    int n,q;cin>>n>>q;
    set<string> s;
    s.insert("AB");
    s.insert("BC");
    s.insert("CE");
    s.insert("CB");
    s.insert("CD");
    s.insert("DB");
    vector<char> states(n+1,'A');
    f(i,0,q){
        string str;cin>>str;
        int p;cin>>p;
        if(states[p]==str[0] && s.find(str)!=s.end())
            states[p] = str[1];
    }
    map<char,vector<int>> ans;
    f(i,0,5) ans['A'+i] = {};
    rep(i,1,n) ans[states[i]].pb(i);
    for(auto it:ans){
        cout<<it.first<<' ';
        for(auto &x:it.second) cout<<x<<' ';
        cout<<endl;
    }

}