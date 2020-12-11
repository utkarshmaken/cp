//BYTE THE BITS

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
    string a,b;
    cin>>a>>b;
    int n = a.size();
    int one = 0,oneb = 0;
    for(auto &ch:a) if(ch=='1') one++;
    for(auto &ch:b) if(ch=='1') oneb++;
    if(one==0 && oneb==0) cout<<"YES"<<endl;
    else if(one>0 && oneb>0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}