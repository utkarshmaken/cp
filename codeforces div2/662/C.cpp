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
        int cnt[n+1] = {0};
        f(i,0,n){
            cin>>a[i];
            cnt[a[i]]++;
        }
        int maxi = 0,num_maxi;
        rep(i,1,n){
            if(cnt[i]==maxi) num_maxi++;
            else if(cnt[i] > maxi){
                maxi = cnt[i];
                num_maxi = 1;
            }
        }
        
        int slots = maxi-1;
        int avail = n - (maxi*num_maxi);
        int ans = avail/(maxi-1);
        ans+=num_maxi-1;
        cout<<ans<<endl;
        
    }

}