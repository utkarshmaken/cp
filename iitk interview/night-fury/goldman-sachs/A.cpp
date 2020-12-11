//JUGGLING
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
    int n;cin>>n;
    vector<int> a(n);
    f(i,0,n) cin>>a[i];
    reverse(a.begin(),a.end());
    vector<int> temp;temp.pb(a[0]);
    f(i,1,n){
        if(a[i]==a[i-1]) continue;
        else temp.pb(a[i]);
    }
    a = temp;n = sz(a);
    int num;cin>>num;
    f(i,0,num){
        int x;cin>>x;
        auto it = upper_bound(all(a),x);
        if(it==a.end()) cout<<1<<' ';
        else{
            int idx = it-a.begin();
            cout<<n-idx+1<<' ';
        }
    }
}