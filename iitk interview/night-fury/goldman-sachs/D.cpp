//TREASURE HUNT
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
const int maxn = 100001;
bool find(vector<int>&a, int i, int &target, vector<bool>& vis, int &n){
    if(i==target) return true;
    int l = i-a[i];
    if(l>=0 && !vis[l]){
        vis[l] = true;
        if(find(a,l,target,vis,n)) return true;
    }
    int r = i+a[i];
    if(r<n && !vis[r]){
        vis[r] = true;
        if(find(a,r,target,vis,n)) return true;
    }
    return false;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        f(i,0,n) cin>>a[i];
        int start;cin>>start;
        --start;
        int target;
        f(i,0,n) if(a[i]==0) target = i;
        vector<bool> vis(n);
        vis[start] = true;
        bool ans = find(a,start,target,vis,n);
        if(ans) cout<<"Yes"<<endl;
        else cout<<"NO"<<endl;

    }
}