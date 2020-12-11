//MINIMUM OPERATIONS TO CREATE DISTINCT ARRAY BY REMOVING MAX AND MIN OF TRIPLETS
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
    int n;cin>>n;
    vector<int> arr(n);
    f(i,0,n) cin>>arr[i];
    map<int,int> m;
    for(auto &x:arr) m[x]+=1;
    int ans = 0,two = 0;
    for(auto it:m){
        if(it.se!=1){
            int x = it.se;
            if(x&1) ans+=x/2;
            else{
                ans+=(x-2)/2;
                two++;
            }
        }
    }
    ans+=(two+1)/2;
    cout<<ans<<endl;
}