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
bool compare(pll a, pll b){
    return a.se < b.se;
}
int main(){
    int n;cin>>n;
    vector<ll> time(n),dir(n);
    f(i,0,n) cin>>time[i];
    cin>>n;
    f(i,0,n) cin>>dir[i];
    vector<pll> enter,exit,ans;
    f(i,0,n){
        if(dir[i]) exit.pb({time[i],i});
        else enter.pb({time[i],i});
    }
    sort(all(enter));sort(all(exit));
    int n1 = sz(enter),n2 = sz(exit);
    int i = 0,j = 0;
    while(i < n1 && j < n2){
        pll en = enter[i],ex = exit[j];
        if(!ans.empty() && en.fi<=ans.back().fi){
            enter[i].fi=ans.back().fi+1;
            en.fi=ans.back().fi+1;
        }
        if(!ans.empty() && ex.fi<=ans.back().fi){
            exit[j].fi=ans.back().fi+1;
            ex.fi=ans.back().fi+1;
        }

        if(en.fi<ex.fi){
            ans.pb(en);
            i++;
        }
        else if(ex.fi < en.fi){
            ans.pb(ex);
            j++;
        }
        else{
            if(ans.empty() || ans.back().fi < en.fi-1){
                ans.pb(ex);
                j++;
            }
            else{
                pll prev = ans.back();
                if(dir[prev.se]==1){
                    ans.pb(ex);
                    j++;
                }
                else{
                    ans.pb(en);
                    i++;
                }
            }
        }
    }
    while(i<n1){
        pll en = enter[i];
        if(!ans.empty() && en.fi<=ans.back().fi){
            enter[i].fi=ans.back().fi+1;
            en.fi=ans.back().fi+1;
        }
        ans.pb(en);
        i++;
    }
    while(j<n2){
        pll ex = exit[j];
        if(!ans.empty() && ex.fi<=ans.back().fi){
            exit[j].fi=ans.back().fi+1;
            ex.fi=ans.back().fi+1;
        }
        ans.pb(ex);
        j++;
    }

    sort(all(ans),compare);
    f(i,0,n) cout<<ans[i].fi<<endl;

}