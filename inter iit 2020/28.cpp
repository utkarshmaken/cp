//MINIMUM IN k CUTS
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
bool poss(vector<int> &arr, int x, int k){
    int cuts = 0;
    for(auto &a:arr){
        if(a<=x) continue;
        if(a%x == 0) cuts+=a/x -1;
        else cuts+=a/x;
    }
    return cuts<=k;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    f(i,0,n) cin>>arr[i];
    int low = 0,high = 1e9;
    int ans;
    while(low <= high){
        int mid = (low+high)/2;
        if(poss(arr,mid,k)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout<<ans<<endl;
}