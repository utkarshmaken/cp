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
    int n;
    cin>>n;
    int cost[n][3];
    f(i,0,n) cin>>cost[i][0]>>cost[i][1]>>cost[i][2];
    int r = 0,g = 0,b = 0;
    f(i,0,n){
        int newr = cost[i][0] + min(g,b);
        int newg = cost[i][1] + min(r,b);
        int newb = cost[i][2] + min(r,g);
        r = newr;g = newg;b = newb;
    }
    cout<<min(r,min(g,b))<<endl;

}