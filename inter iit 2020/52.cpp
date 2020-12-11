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
    vector<string> T(n),R(n);
    f(i,0,n) cin>>T[i];
    f(i,0,n) cin>>R[i];
    map<int,int> passed,total;
    f(i,0,n){
        string t = T[i];
        int grp = t[4] - '0';
        total[grp]+=1;
        if(R[i] == "OK") ++passed[grp];
    }
    double p = 0,tot = 0;
    for(auto it:total){
        ++tot;
        if(passed[it.fi] == it.se) ++p;
    }
    cout<<floor(100*p/tot)<<endl;
}