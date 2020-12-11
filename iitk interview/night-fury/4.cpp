//SUBSEQUENCE REMOVAL
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
    map<int,int> m;
    for(auto &x:arr) ++m[x];
    map<int,int> rem;
    for(auto it:m){
        if(it.se>1) 
            rem[it.fi] = it.se-1;
    }
    vector<int> ans;
    int res = 0;
    int i = 0;
    for(auto it:rem){
        int val = it.fi,x = it.se;
        while(i<n && x>0){
            if(arr[i] == val){
                ans.pb(val);
                --x;
            }
            ++i;
        }
        if(x!=0){
            res = 1;
            break;
        }
    }
    if(res) cout<<-1<<endl;
    else{
        for(auto &x:ans) cout<<x<<' ';
    }
}