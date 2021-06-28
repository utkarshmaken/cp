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

int ask(int l, int r){
    int ans;
    cout<<"? "<<l<<" "<<r<<endl;
    cout.flush();
    cin>>ans;
    return ans;
}

int main(){
    int n;
    cin>>n;
    int smax = ask(1,n);
    int i1 = (smax == 1 ? 0 : ask(1,smax));
    if(i1 == smax){
        int l = 1, r = smax;
        while(l < r-1){
            int mid = (l + r)/2;
            if(ask(mid,smax) == smax)
                l = mid;
            else
                r = mid;
        }
        if(ask(l,smax) == smax)
            cout<<"! "<<l<<endl;
        else
            cout<<"! "<<r<<endl;
    }
    else{
        int l = smax, r = n;
        while(l < r-1){
            int mid = (l + r)/2;
            if(ask(smax,mid) == smax)
                r = mid;
            else
                l = mid;
        }
        if(ask(smax,r) == smax)
            cout<<"! "<<r<<endl;
        else
            cout<<"! "<<l<<endl;
    }

}