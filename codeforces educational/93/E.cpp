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
const int maxn = 100001;

int main(){
    int n;cin>>n;
    multiset<ll> l,f,ftemp,lf;
    int tp,d;
    ll suml = 0,sumf = 0,sumlf = 0;
    cout<<endl;
    f(i,0,n){
        cin>>tp>>d;
        if(tp){
            if(d>0){
                l.insert(d);
                if(!ftemp.empty()){
                    lf.insert(*(--ftemp.end()));
                    sumlf+=*(--ftemp.end());
                    ftemp.erase(--ftemp.end());
                }
            }
            else{
                l.erase(l.find(-1*d));
                if(sz(lf)>sz(l)){
                    ftemp.insert(*(lf.begin()));
                    sumlf-=*(lf.begin());
                    lf.erase(lf.begin());
                }
            }
            suml+=d;
        }
        else{
            if(d>0){
                f.insert(d);
                if(sz(lf)<sz(l)){
                    lf.insert(d);
                    sumlf+=d;
                }
                else
                    ftemp.insert(d);
                
            }
            else{
                f.erase(f.find(-1*d));
                if(ftemp.find(-1*d)!=ftemp.end())
                    ftemp.erase(ftemp.find(-1*d));
                else{
                    lf.erase(lf.find(-1*d));
                    sumlf+=d;
                }
            }
            sumf+=d;
        }
        cout<<suml<<' '<<sumf<<' '<<sumlf<<endl;
        //if(sz(l)>=sz(f)) cout<<suml + 2*sumf<<endl;
        //else cout<<suml + 2*sumlf + (sumf-sumlf)<<endl;

    }

}