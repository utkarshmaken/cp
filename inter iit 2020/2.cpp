//No. of increments to make all elements equal in array
//One increment is increasing n-1 elements except 1
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
    int sum = 0,mini =INT_MAX;
    f(i,0,n){
        sum+=arr[i];
        mini = min(mini,arr[i]);
    }
    int ans = sum - n*mini;
    cout<<ans<<endl;

}