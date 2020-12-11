//VIRUS
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
#define mp make_pair
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
#define endl '\n'
using namespace std;
const int mod = 1000000007;
const int maxn = 100001;

int main(){
    int n;cin>>n;
    vector<int> x(n);
    f(i,0,n) cin>>x[i];
    sort(all(x));
    float e = (x[n-1]-x[0])/6.0;
    int val = e*100;
    if(val%10 >= 5) val = val+10-val%10;
    else val = val-val%10;
    e = val/100.0;
    printf("%.1f",e);
}