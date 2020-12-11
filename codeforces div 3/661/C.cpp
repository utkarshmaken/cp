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
const int maxn = 200000;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> w(n);
        map<int,int> m;
        f(i,0,n){
            cin>>w[i];
            m[w[i]]++;
        }
        int maxi = 0;
        rep(i,2,2*n){
            int t = 0;
            rep(j,1,i/2){
                if(i%2==0 && j==i/2)
                    t+=m[j]/2;
                else
                    t+=min(m[j],m[i-j]);
            }
            maxi = max(maxi,t);

        }
        cout<<maxi<<endl;
    }

}