//
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
    string s1,s2;
    cin>>s1>>s2;

    map<char,vector<int>> m;
    int i = 0;
    for(auto &x:s2){
        if(x==s1[0] || x==s1[1] || x==s1[2])
            m[x].push_back(i);
        ++i;
    }
    long ans = 0;
    int n = m[s1[2]].size();
    for(auto x:m[s1[0]]){
        auto it = upper_bound(m[s1[1]].begin(),m[s1[1]].end(),x);
        for(;it!=m[s1[1]].end();++it){
            auto it1 = upper_bound(m[s1[2]].begin(),m[s1[2]].end(),*it);
            if(it1!=m[s1[2]].end())
                ans+=n-(it1-m[s1[2]].begin());
        }
    }
    cout<<ans<<endl;

}