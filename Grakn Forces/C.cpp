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
    vector<ld> res(t);
    f(tt,0,t){
        ll n,l;
        cin>>n>>l;
        vector<ld> a(n+2);
        rep(i,1,n) cin>>a[i];
        a[0] = 0.0;a[n+1] = l*1.0;
        vector<ld> ta(n+2),tb(n+2);
        ld speed = 1.0;
        ta[0] = 0.0;
        rep(i,1,n+1){
            ta[i] = ta[i-1] + (1.0*(a[i]-a[i-1]))/speed;
            speed+=1.0;
        }
        speed = 1.0;tb[n+1] = 0.0;
        repd(i,n,0){
            tb[i] = tb[i+1] + (1.0*(a[i+1] - a[i]))/speed;
            speed+=1.0;
        }

        int low = 0,high = n+1;
        ld ans = 0.0;int f = 0;
        while(low<high-1){
            int mid = (low+high)/2;
            if(ta[mid] == tb[mid]){
                f = 1;ans = ta[mid];break;
            }
            else if(ta[mid] < tb[mid])
                low = mid;
            else
                high = mid;
        }
        //cout<<low<<high<<endl;
        if(f==1){
            res[tt] = ans;
            continue;
        }
        ld s1 = 1.0*(low+1), s2 = 1.0*(n+2-high);
        ld dist;

        dist = a[high] - (ta[low] - tb[high])*s2 - a[low];
        //cout<<dist<<endl;
        ans = ta[low] + ((dist*10000)/(s1+s2))/10000;
        res[tt] = ans;
    }
    f(i,0,t) printf("%Lf\n",res[i]);
}