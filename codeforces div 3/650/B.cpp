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

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        f(i,0,n) cin>>v[i];
        int ans = 0,net = 0;
        f(i,0,n){
            if(i&1 && !(v[i]&1)){
                ans++;net++;
            }
            else if(!(i&1) && v[i]&1)
                net--;
        }
        if(net)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;

    }

}