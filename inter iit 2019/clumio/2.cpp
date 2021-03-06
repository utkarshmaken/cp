//Given N cars placed at some positions on a 
//number line. Find the minimum length of shed
// such that at least K cars are under it.
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
    int n;
    cin>>n;
    vector<int> arr(n);
    f(i,0,n) cin>>arr[i];
    sort(all(arr));
    int k;cin>>k;
    int mini = arr[n-1] - arr[0];
    f(i,k-1,n){
        int s = arr[i-k+1];
        int e = arr[i];
        mini = min(mini,e-s);
    }
    cout<<mini<<endl;
}
