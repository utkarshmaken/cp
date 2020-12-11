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
const int maxn = 1e5;

int main(){
    string s;
    cin>>s;
    int n = sz(s);
    vector<int> num(n+1);
    int curr = 0;
    f(i,0,n){
        curr^=(1<<(s[i]-'a'));
        num[i+1] = curr;
    }
    int q;cin>>q;
    f(i,0,q){
        int l,r,k;
        cin>>l>>r>>k;
        int parity = num[l]^num[r+1];
        int setb = 0;
        while(parity!=0){
            setb+=(parity&1);
            parity = parity>>1;
        }
        if(setb/2 <= k)
            cout<<1<<endl;
        else
            cout<<0<<endl;

    }
}