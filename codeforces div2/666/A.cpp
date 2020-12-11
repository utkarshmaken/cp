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
        int n;
        cin>>n;
        vector<string> s(n);
        f(i,0,n) cin>>s[i];
        vector<int> freq(26);
        f(i,0,n)
            for(auto &ch:s[i])
                ++freq[ch-'a'];
        bool flag = true;
        for(auto &x:freq)
            if(x%n!=0){
                flag = false;
                break;
            }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }

}