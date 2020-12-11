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
    
    rep(n,2,25){
    int grid[n+1][n+1];
    grid[1][1] = 1;
    int start = 1;
    for(int t = 2;t<=2*n;t++){
        for(int i = min(t-1,n);i>=max(1,t-n);i--){
            int j = t-i;
            grid[i][j] = start++;
        }
    }
    
    ll mini = 0,maxi = 0;
    rep(i,1,n) {mini+=grid[i][1];maxi+=grid[1][i];}
    rep(i,2,n) {mini+=grid[n][i];maxi+=grid[i][n];}
    rep(k,mini,maxi){
        ll diff = k-mini;
        int dend = diff/(n-1);
        int drem = n-1,rrem = n-1;
        string ans(dend,'D');drem-=dend;
        int rem = diff%(n-1);
        string temp(n-1-rem,'R');rrem-=(n-1-rem);
        ans = temp+ans;
        if(drem>0){ans = 'D' + ans;drem-=1;}
        string temp1(rem,'R');
        if(rrem>0) ans = temp1 + ans;
        string temp2(drem,'D');
        ans = temp2 + ans;
        cout<<ans<<' '<<ans.size()<<endl;;

    }
    cout<<endl;
    }

}