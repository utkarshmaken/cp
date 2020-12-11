//K empty Slots
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
    int n;cin>>n;
    vector<int> a(n+1);
    rep(i,1,n) cin>>a[i];
    int k;cin>>k;
    set<int> bloomed;
    int f = 0;
    rep(i,1,n){
        int x = a[i];
        if(bloomed.empty()) bloomed.insert(x);
        else{
            auto it = bloomed.lower_bound(x);
            if(it!=bloomed.begin()){
                --it;
                if(*it==x-k-1){
                    cout<<i<<endl;
                    f = 1;
                    break;
                }
            }
            it = bloomed.upper_bound(x);
            if(it!=bloomed.end()){
                if(*it==x+k+1){
                    cout<<i<<endl;
                    f = 1;
                    break;
                }
            }
            bloomed.insert(x);
        }
    }
    if(!f) cout<<-1<<endl;
}
