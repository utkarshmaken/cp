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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int net_right = 0;
    int q;cin>>q;
    while(q--){
        int dir,amt;
        cin>>dir>>amt;
        if(dir == 0) net_right-=amt;
        else net_right+=amt;
    }
    if(net_right > 0){
        net_right%=n;
        s = s.substr(n - net_right) + s.substr(0,n-net_right);
        cout<<s<<endl;
    }
    else if(net_right<0){
        int net_left = -1*net_right;
        net_left%=n;
        s = s.substr(net_left) + s.substr(0,net_left);
        cout<<s<<endl;
    }
    else
    {
        cout<<s<<endl;
    }
    
}