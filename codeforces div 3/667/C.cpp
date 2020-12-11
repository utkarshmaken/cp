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
        int n,x,y;
        cin>>n>>x>>y;
        int d = y-x;
        int diff = 1;
        while(true){
            if(d%diff==0 && d/diff<n) break;
            ++diff;
        }
        vector<int> ans;
        int s = x;
        while(n>0 && s<=y){
            ans.pb(s);
            --n;s+=diff;
        }
        s = x-diff;
        while(n>0 && s>0){
            ans.pb(s);
            --n;s-=diff;
        }
        s = y+diff;
        while(n>0){
            ans.pb(s);
            --n;s+=diff;
        }
        for(auto &c:ans) cout<<c<<' ';
        cout<<endl;

    }

}