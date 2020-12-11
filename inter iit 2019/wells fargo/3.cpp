//MINIMUM MERGE OP TO MAKE ARRAY PALINDROME
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
    int i = 0,j = n-1;
    int ans = 0;
    while(i<j){
        if(arr[i] == arr[j]){
            ++i;--j;
        }
        else{
            if(arr[i] > arr[j]){
                arr[j-1] += arr[j];
                --j;++ans;
            }
            else{
                arr[i+1] += arr[i];
                ++i;++ans;
            }
        }
    }
    cout<<ans<<endl;

}