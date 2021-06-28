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
        int n;
        cin>>n;
        int digits = 0, temp = n, first, num = 0;
        
        while(temp){
            ++digits;
            first = temp % 10;
            temp /= 10;
            num = num * 10  + 1;
        }
        int ans = (digits - 1) * 9;
        ans += (first - 1);
        if(n >= first * num) ++ans;
        cout<<ans<<endl;
    }
}