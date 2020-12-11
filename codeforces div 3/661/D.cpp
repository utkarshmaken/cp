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
        string s;
        cin>>s;
        set<int> one,zero;
        f(i,0,n){
            if(s[i]=='0') zero.insert(i);
            else one.insert(i);
        }
        int ans = 0;
        vector<int> pos(n);
        while(!one.empty() && !zero.empty()){
            int start,idx;
            if(*zero.begin() < *one.begin())
                start = 0,idx = *zero.begin();
            else
                start = 1,idx = *one.begin();
            while(idx < n){
                pos[idx] = ans;
                if(start==0){
                    zero.erase(idx);
                    idx = one.upper_bound(idx)==one.end()?n:*one.upper_bound(idx);
                    start = 1;
                }
                else{
                    one.erase(idx);
                    idx = zero.upper_bound(idx)==zero.end()?n:*zero.upper_bound(idx);
                    start = 0;
                }
            }
            ans++;
        }
        while(!one.empty()){
            pos[*one.begin()] = ans++;
            one.erase(one.begin());
        }
        while(!zero.empty()){
            pos[*zero.begin()] = ans++;
            zero.erase(zero.begin());
        }
        cout<<ans<<endl;
        f(i,0,n) cout<<pos[i]+1<<' ';
        cout<<endl;
    }

}