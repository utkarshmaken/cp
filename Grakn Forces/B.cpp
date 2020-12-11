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
vector<int> a(100);
int n,k0;
int find(int idx, int k, int c){
    if(idx==n) return 0;
    int diff = 1;
    set<int> s;s.insert(0);
    int i = idx;
    while(i<n){
        if(s.empty() || s.find(a[i]-c)==s.end()){
            if(diff==k) break;
            else{
                ++diff;
                s.insert(a[i]-c);
            }
        }
        ++i;
    }
    if(i==idx) return -1;
    int m = find(i,k,a[i-1]);
    if(m!=-1) return 1+m;
    else return -1;
    
    
}
int main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>k0;
        f(i,0,n) cin>>a[i];
        set<int> s;
        int i = 0,diff = 0;
        while(i<n){
            if(s.empty() || s.find(a[i])==s.end()){
                if(diff==k0) break;
                else{
                    ++diff;
                    s.insert(a[i]);
                }
            }
            ++i;
        }
        int m = find(i,k0,a[i-1]);
        if(m!=-1) cout<<m+1<<endl;
        else cout<<-1<<endl;
    }
}