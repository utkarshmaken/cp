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
        int n,k;
        cin>>n>>k;
        vector<int> a(n),w(k);
        f(i,0,n) cin>>a[i];
        f(i,0,k) cin>>w[i];
        sort(all(a),greater<int>());
        sort(all(w));
        ll happi = 0;
        int index = k-1;
        f(i,0,k){
            if(w[i] == 1)
                happi+= 2*a[i];
            else
            {
                index+=w[i]-1;
                happi+= a[i] + a[index];
            }
        }
        cout<<happi<<endl;
    }

}