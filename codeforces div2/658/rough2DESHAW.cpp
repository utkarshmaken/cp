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
int maxDiff(vector<int> arr){
    int n = arr.size();
    int maxi = 0;
    for(int i = 0;i<n;i++)
        maxi+= max(0,arr[i]-arr[i+1]);
    return maxi;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    f(i,0,n) cin>>arr[i];
    cout<<maxDiff(arr)<<endl;

}
    