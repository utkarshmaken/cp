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

int n,m;
string s,t;

int main(){
    cin>>n>>m;
    cin>>s>>t;
    int left[m],right[m];
    for(int i = 0, j = 0; i < n && j < m; i++){
        if(s[i] == t[j])
            left[j++] = i;
    }
    for(int i = n-1, j = m-1; i >= 0 && j >= 0; i--){
        if(s[i] == t[j])
            right[j--] = i;
    }
    int ans = 0;
    for(int i = 0; i < m-1; i++)
        ans = max(ans, right[i+1]-left[i]);
    cout<<ans<<endl;
}