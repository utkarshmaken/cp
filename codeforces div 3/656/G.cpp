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
using namespace std;
const int mod = 1000000007;
const int maxn = 200000;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        map<int,set<int>> ma,mb;
        f(i,0,n) cin>>a[i],ma[a[i]].insert(i);
        f(i,0,n) cin>>b[i],mb[b[i]].insert(i);
        bool flag = true;
        rep(i,1,n) 
            if(sz(ma[i]) + sz(mb[i])!=2){
                flag = false;
                break;
            }
        if(!flag){
            cout<<-1<<endl;
            continue;
        }

        vector<int> ans; 
        f(i,0,n){
            

        }

    }

}