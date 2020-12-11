//CLOSEST SUM SUBSEQUENCE TO K
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
    long arr[40];
    int n,k;
    cin>>n>>k;
    f(i,0,n) cin>>arr[i];
    if(k<0){
        k*=-1;
        f(i,0,n) arr[i]*=-1;
    }
    sort(arr,arr+n);
    unordered_set<long> s;
    vector<int> sum(2*k+1);
    sum[0] = 1;
    if(arr[0] < 0) s.insert(arr[0]);
    else sum[arr[0]] = 1;
    f(i,1,n){
        vector<int> ns(2*k+1);
        rep(j,0,2*k){
            ns[j] = max(ns[j],sum[j]);
            if(arr[i] <=j) ns[j] = max(ns[j],sum[j-arr[i]]);
        }
        unordered_set<long> news;
        for(auto x:s){
            if(x+arr[i]>=0 && x+arr[i]<=2*k)
                ns[x+arr[i]] = 1;
            else
                news.insert(x+arr[i]);
        }
        s.insert(news.begin(),news.end());
        sum = ns;
    }
    long ans = 1e18;
    repd(i,k,0)
        if(sum[i] == 1){
            ans = abs(k-i);
            break;
        }
    rep(i,k+1,2*k)
        if(sum[i] == 1){
            ans = min(ans,1L*abs(i-k));
            break;
        }
    if(ans == 1e18){
        for(auto x:s)
            ans = min(ans,abs(x-k));
    }
    cout<<ans<<endl;
}