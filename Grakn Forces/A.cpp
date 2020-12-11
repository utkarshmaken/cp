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
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        f(j,0,3) f(i,0,n) cin>>a[i][j];
        vector<int> ans(n);
        ans[0] = a[0][0];
        f(i,1,n-1){
            if(a[i][0]!=ans[i-1]) {ans[i] = a[i][0];continue;}
            if(a[i][1]!=ans[i-1]) {ans[i] = a[i][1];continue;}
            ans[i] = a[i][2];
        }
        if(a[n-1][0]!=ans[n-2] && a[n-1][0]!=ans[0]) ans[n-1] = a[n-1][0];
        else if(a[n-1][1]!=ans[n-2] && a[n-1][1]!=ans[0]) ans[n-1] = a[n-1][1];
        else ans[n-1] = a[n-1][2];
        f(i,0,n) cout<<ans[i]<<' ';
        cout<<endl;
    }
}