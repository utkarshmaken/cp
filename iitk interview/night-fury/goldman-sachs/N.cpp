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
    int m;cin>>m;
    cin>>n;
    vector<int> a(n+2);
    rep(i,1,n) cin>>a[i];
    a[0] = 0;a[n+1] = m;
    sort(all(a));

    vector<int> on(n+2),off(n+2);
    on[n+1] = 0;off[n+1] = 0;
    repd(i,n,0){
        if(i&1){
            off[i] = off[i+1] + a[i+1]-a[i];
            on[i] = on[i+1];
        }
        else{
            on[i] = on[i+1] + a[i+1] - a[i];
            off[i] = off[i+1];
        }
    }

    int maxi = on[0];
    repd(i,n,0){
        if(i&1 && (a[i+1]!=a[i]+1 || a[i-1]!=a[i]-1))
            maxi = max(maxi,on[0] - on[i] + off[i]);
    }
    cout<<maxi-1<<endl;
    
}