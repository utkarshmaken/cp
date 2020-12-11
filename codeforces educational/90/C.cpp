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
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int len  = sz(s);
        vector<int> a(len+1,0);
        ll curr = 0,res = 0;
        rep(i,1,len)
            a[i] = a[i-1] + (s[i-1]=='+'?1:-1);

        for(int i = 1;i<=len;i++){
            if(curr+a[i]<0){
                res+=i;
                curr++;
                if(i==len)
                    i = len-1;
            }
        }
        res+=len;
        cout<<res<<endl;
    }

}