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
    int n,q;
    cin>>n>>q;
    vector<int> p(n);
    f(i,0,n) cin>>p[i];
    sort(all(p));
    int maxi = 0,idx;
    f(i,1,n){
        if(p[i]-p[i-1]>maxi){
            maxi = p[i]-p[i-1];
            idx = i;
        }
    }
    int ans = p[n-1]-p[0]-maxi;
    cout<<ans<<endl;

    set<int> s;
    multiset<int> gaps;
    f(i,0,n) s.insert(p[i]);
    f(i,1,n) gaps.insert(p[i]-p[i-1]);
    int small = p[0],large = p[n-1],p1 = p[idx-1],p2 = p[idx];
    int q;cin>>q;
    rep(i,0,q){
        int t,x;
        cin>>t>>x;
        if(t==1){
            if((x>=small && x<=p1) || (x>=p2 && x<=large)){
                cout<<ans<<endl;
                s.insert(x);
            }
            else{
                if(x<small){
                    s.insert(x);
                    gaps.insert(small-x);
                }
                else if(x>large){
                    s.insert(c)
                }

            }
            
        }
        else{

        }
    }

    
}