//REPLACE FOR X CODECHEF OCT LONG CONTEST
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

int main(){
    int t;cin>>t;
    while(t--){
        int n,x,p,k;
        cin>>n>>x>>p>>k;
        vector<int> a(n);
        f(i,0,n) cin>>a[i];
        sort(all(a));
        int ans = 0;
        if(a[p-1]==x){
            cout<<0<<endl;
            continue;
        }
        if(x < a[0]){
            if(p<=k)
                cout<<p<<endl;
            else
                cout<<-1<<endl;
            continue;
        }
        if(x > a[n-1]){
            if(k<=p)
                cout<<n-p+1<<endl;
            else 
                cout<<-1<<endl;
            continue;
        }

        auto it = upper_bound(all(a), x);
        --it;
        int  less_eq_x = it - a.begin() + 1;
        if(less_eq_x < p){
            if(k<p)
                cout<<-1<<endl;
            else
                cout<<(p - less_eq_x)<<endl;
        }
        else{

            if(k>p) cout<<-1<<endl;
            else{
                int less_x = 0;
                auto it = lower_bound(all(a), x);
                if(it!=a.begin()){
                    --it;
                    less_x = it - a.begin() + 1;
                }
                if(less_x < p) cout<<0<<endl;
                else cout<<(less_x - (p-1))<<endl;
            }
        }
    }
}


