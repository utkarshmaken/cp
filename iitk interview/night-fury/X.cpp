//MINIMIZE MAX DIFF
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
bool poss(vector<int> &arr, int k, int diff, int n){
    int rem = 0,prev = 0;
    for(int i = 1;i<n-1 && rem<k;i++){
        if(arr[i] - arr[prev] <= diff && arr[i+1]-arr[prev]<=diff)
            ++rem;
        else
            prev = i;
    }
    return rem==k;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    f(i,0,n) cin>>arr[i];
    int low = 0,high = arr[n-1] - arr[0];
    f(i,1,n) low = max(low,arr[i] - arr[i-1]);
    while(low<high){
        int mid = (low + high)/2;
        if(poss(arr,k,mid,n))
            high = mid;
        else
            low = mid+1;
    }
    cout<<low<<endl;
}