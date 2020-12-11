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
using namespace std;
const int mod = 1000000007;
const int maxn = 100000;
int v[maxn];
int max_possible[maxn];

ll find(int x,int n){
    ll days = 0;int i = 0,count = 0; 
    while(i!=n){
        while(i<n && x>=v[i])
          i++;
        if(i==n)
            break;
        if(i>0 && 2*v[i-1]>x){
            days++;count++;
            x = 2*v[i-1];
            v[i-1] = 0;
            continue;
        }
        while(x<v[i]){
            days++;
            x*=2;
        }
    }
    return days + n-count;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        f(i,0,n) scanf("%d",&v[i]);
        sort(v,v+n);
        f(i,0,n) max_possible[i] = v[i];
        ll days = find(x,n);
        cout<<days<<endl;
    }
}

