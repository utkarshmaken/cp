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

int main(){
    int t;
    cin>>t;
    while(t--){
       int n;cin>>n;
       vector<int> a(n);
       f(i,0,n) cin>>a[i];
       vector<pii> arr(n);
       f(i,0,n) arr[i].fi = a[i],arr[i].se = i;
       sort(all(arr));
       vector<int> temp;
       f(i,0,n) if(arr[i].fi != a[i]) temp.pb(a[i]);
       a.resize(temp.size());
       a = temp;n = sz(temp);
       f(i,0,n) arr[i].fi = a[i],arr[i].se = i;
       sort(all(arr));
       vector<bool> vis(n,false);
       bool flag = true;
       f(i,0,n){
           if(arr[i].se==i || vis[i]) continue;
           vis[i] = true;
           int j = arr[i].se;
           vector<int> cycle;cycle.pb(i);
           while(!vis[j]){
                vis[j] = true;
                cycle.pb(j);
                j = arr[j].se;
            }
            int len = sz(cycle);
            vector<int> cnt(len);
            for(int i = 0;i<len;i++){
                for(int j = i+1;j<len;j++){
                    if(__gcd(arr[cycle[i]].fi,arr[cycle[j]].fi) == arr[0].fi){
                        cnt[i]++;cnt[j]++;
                    }
                }
            }
            bool s = false;
            for(auto x:cnt) 
                if(x==len-1){
                    s = true;
                    break;
                }
            if(!s){
                flag = false;
                break;
            }

        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl; 
    }
}