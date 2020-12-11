//BITWISE XOR SUBSEQUENCES
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
    int k;cin>>k;
    unordered_map<int,int> m;
    int maxi = 1;
    m[arr[0]] = 1;
    for(int i = 1;i<n;i++){
        int len = m[arr[i]^k] + 1;
        m[arr[i]] = len;
        maxi = max(maxi,len);
    }
    cout<<maxi<<endl;
}