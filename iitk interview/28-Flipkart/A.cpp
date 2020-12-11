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
    int n,m;
    cin>>n>>m;
    vector<pii> pos(m);
    f(i,0,m) cin>>pos[i].fi;
    cin>>m;
    f(i,0,m) cin>>pos[i].se;
    sort(all(pos));
    int maxi = pos[0].fi-1;
    int i = 0,j = 1;
    while(j<m){
        maxi = max(maxi,pos[j].fi-pos[i].se - 1);
        if(pos[j].fi<=pos[i].se){
            if(pos[i].se >= pos[j].se)
                j++;
            else{
                i = j;
                j = i+1;
            }
        }
        else{
            i = j;
            j = i+1;
        }
    }
    maxi = max(maxi,n-pos[i].se);
    cout<<maxi<<endl;
    

}