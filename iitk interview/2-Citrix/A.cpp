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
    int x,n;
    cin>>x>>n;
    vector<int> a(n);
    f(i,0,n) cin>>a[i];
    int ans = 0;
    deque<int> q;
    f(i,0,n){
        while(!q.empty() && q.front()<=i-x) q.pop_front();
        while(!q.empty() && a[q.back()]>=a[i]) q.pop_back();
        q.push_back(i);
        if(i<x-1) continue;
        ans = max(ans,a[q.front()]);
    }
    cout<<ans<<endl;
}