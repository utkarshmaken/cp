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
const int maxn = 2000000;
double time(int n){
    if(n==2) return 0.5;
    if(n==3) return 1.0;
    if(n&1) return 0.5 + max(time(n/2),time(n/2 + 1));
    else return 0.5 + time(n/2);
}
int main(){
    int n,x;
    cin>>n>>x;
    double t = time(n);
    if(t<=x*1.0)
        cout<<1<<endl;
    else
        cout<<0<<endl;
}