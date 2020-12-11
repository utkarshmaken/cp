//STRING REDUCTION
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
int n;

bool poss(string &s, string &t, vector<int> &arr, int rem){
    vector<int> temp(n);
    f(i,0,rem) temp[arr[i]] = -1;
    int idx = 0,len = sz(t);
    f(i,0,n){
        if(temp[i]!=-1 && s[i] == t[idx])
            ++idx;
    }
    return idx == len;
}
int main(){
    string s,t;
    cin>>s>>t;
    n = sz(s);
    vector<int> arr(n);
    f(i,0,n){
        cin>>arr[i];
        --arr[i];
    }
    int ans = 0;
    if(!poss(s,t,arr,0)){
        cout<<0<<endl;
        return 0;
    }
    int low = 1,high = n;
    while(low <= high){
        int mid = (low+high)/2;
        if(poss(s,t,arr,mid)){
            ans = mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
        
    }
    cout<<ans<<endl;
}