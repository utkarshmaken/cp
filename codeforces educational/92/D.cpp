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
 
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(l2<l1){
            swap(l1,l2);
            swap(r1,r2);
        }
        ll ans = 0,total = 0;

        if(l2>=r1 || r2>=r1){
            total = l2<r1?(r1-l2)*n:0;
            k-=total;
            if(k<=0){
                cout<<0<<endl;
                continue;
            }

            ll eq = r2-r1 + l2-l1;
            ll extra = l2<r1?eq:r2-l1;
            ll num_eq = k/extra;
            if(num_eq>=n){
                ans+=n*eq;
                ll rem = k - n*(extra);
                ans+=rem*2;
            }
            else{
                ans+=num_eq*eq;
                ll rem = k - num_eq*(extra);
                ans+= min(2*rem,rem + max(0ll,l2 - r1));
            }
        }
        else{
            total = n*(r2-l2);
            k-=total;
            if(k<=0){
                cout<<0<<endl;
                continue;
            }

            ll eq = r1-r2+ l2-l1;
            ll extra = eq;
            ll num_eq = k/(extra);
            if(num_eq>=n){
                ans+=n*eq;
                ll rem = k - n*(extra);
                ans+=rem*2;
            }
            else{
                ans+=num_eq*eq;
                ll rem = k - num_eq*(extra);
                ans+= rem;
            }
        }
        cout<<ans<<endl;
    }

}