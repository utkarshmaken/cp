//NEXT GREATER
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
    int n;cin>>n;
    vector<int> h(n);
    f(i,0,n) cin>>h[i];
    int ans = 0;
    stack<int> s;
    s.push(n-1);
    repd(i,n-2,0){
        while(!s.empty() && h[s.top()] < h[i])
            s.pop();
        if(s.empty())
            ans+=(n-1-i);
        else
            ans+=(s.top()-i);
        s.push(i);
    }
    cout<<ans<<endl;
}