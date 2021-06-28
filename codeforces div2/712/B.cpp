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
        int n;cin>>n;
        string a,b;
        cin>>a>>b;
        int one = 0,zero = 0, inv = 0;
        f(i,0,n){
            if(a[i] == '0') ++zero;
            else ++one;
        }
        bool ans = true;
        repd(i,n-1,0){
            char curr = (inv&1)?!(a[i]-'0') + '0':a[i];
            if(curr != b[i]){
                if(i%2 == 0){
                    ans = false;
                    break;
                }
                else{
                    if(one != zero){
                        ans = false;
                        break;
                    }
                    ++inv;
                    swap(zero,one);
                    if(curr == '1') --zero;
                    else --one;
                }
            }
            else{
                if(curr == '1') --one;
                else --zero;
            }
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }

}