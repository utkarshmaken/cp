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
const int maxn = 2e5;

int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int n = sz(s);
        bool flag = false;
        f(i,0,n){
            if(s[n-1-i] != 'a'){
                cout<<"YES"<<endl;
                cout<<s.substr(0,i) + 'a' + s.substr(i)<<endl;
                flag = true;
                break;
            }
        }
        if(!flag)
            cout<<"NO"<<endl;
    }

}