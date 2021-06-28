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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(s[0] == '0' || s[n-1] == '0'){
            cout << "NO" << endl;
            continue;
        }
        int one = 0;
        for(auto &x:s)
            if(x == '1')
                ++one;
        if(one & 1){
            cout << "NO" << endl;
            continue;
        }

        string a(n,'?'), b(n,'?');
        one /= 2;
        bool f = 1;
        f(i,0,n){
            if(s[i] == '1'){
                if(one){
                    a[i] = b[i] = '(';
                    --one;
                }
                else{
                    a[i] = b[i] = ')';
                }
            }
            else{
                if(f){
                    a[i] = '(';
                    b[i] = ')';
                }
                else{
                    a[i] = ')';
                    b[i] = '(';
                }
                f = !f;
            }
        }
        cout << "YES" << endl;
        cout << a << '\n' << b << '\n';

    }

}