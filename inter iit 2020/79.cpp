//DISTINCT PAIRS
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
const int maxn = 1e5;

int main(){
    int n;cin>>n;
    vector<int> a(n);
    f(i,0,n) cin>>a[i];
    int k;cin>>k;
    sort(all(a));
    vector<int> arr;
    int ans = 0,by_two = 0;
    arr.pb(a[0]);
    if(k%2==0 && a[0] == k/2) by_two+=1;
    f(i,1,n){
        if(a[i]!=a[i-1])
            arr.pb(a[i]);
        if(k%2==0 && a[i] == k/2) by_two+=1;
    }
    if(by_two>1) ++ans;
    int i = 0,j = sz(arr)-1;
    while(i<j){
        if(arr[i] + arr[j] == k){
            ++ans;
            ++i;--j;
        }
        else if(arr[i] + arr[j] < k)
            ++i;
        else
            --j; 
    }
    cout<<ans<<endl;

}