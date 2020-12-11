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
        vector<int> a(n);
        f(i,0,n) cin>>a[i];
        sort(all(a));
        vector<int> k(n);
        f(i,0,n){
            int digit = 0,x = a[i];
            while(x>0){
                x/=2;
                digit++;
            }
            k[i] = digit;
        }

        int maxi = INT_MIN;
        f(i,0,n){
            f(j,i,n){
                int poss = a[i]*((1<<k[j]) - 1) - a[j]*((1<<k[i]) - 1);
                if(j!=i) poss = max(poss,-1*poss);
                maxi = max(maxi,poss);
            }
        }
        cout<<maxi<<endl;
        f(i,0,n) cout<<k[i]<<endl;


    }

}