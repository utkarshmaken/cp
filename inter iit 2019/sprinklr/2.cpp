//BAR GRAPH
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
vector<int> arr;
int diff(int i){
    return arr[i+1]-arr[i];
}
int main(){
    int n,k;cin>>n>>k;
    arr.resize(n);
    f(i,0,n) cin>>arr[i];
    int ans = INT_MAX;
    int len = n-k-1;
    deque<int> q;
    f(i,0,n-1){
        while(!q.empty() && q.front()<=i-len) q.pop_front();
        while(!q.empty() && diff(i) >= diff(q.back())) q.pop_back();
        q.push_back(i);
        if(i>=len-1)
            ans = min(ans,diff(q.front()));
    }
    cout<<ans<<endl;
}