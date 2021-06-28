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
int n;

bool check(string s){
    int open = 0;
    f(i,0,n){
        if(s[i] == '(') ++open;
        else --open;
        if(open < 0) return false;
    }
    return open == 0;
}

int main(){
    int t;cin>>t;
    while(t--){
        cin>>n;
        string s;cin>>s;
        string a(n,'('), b(n,'(');
        int uneq = 0;
        int open_a = n, open_b = n;
        f(i,0,n){
            if(s[i] == '0'){
                if(uneq%2 == 0){
                    a[i] = '(';
                    b[i] = ')';--open_b;
                }
                else{
                    a[i] = ')';--open_a;
                    b[i] = '(';
                }
                ++uneq;
            }
        }
        if(uneq&1){
            cout<<"NO"<<endl;
            continue;
        }
        int curr_a = 2*open_a - n, curr_b = 2*open_b - n;
        repd(i,n-1,0){
            if(s[i] == '0'){
                if(a[i] == '('){
                    --curr_a;++curr_b;
                }
                else{
                    ++curr_a;--curr_b;
                }
                continue;
            }

            if(open_a > n/2 && open_b > n/2 && curr_a > 0 && curr_b > 0){
                a[i] = ')';b[i] = ')';
                --open_a;--open_b;
            }
            --curr_a;--curr_b;
        }
        /*int curr_a = 0, curr_b = 0;
        f(i,0,n){
            if(s[i] == '1') continue;
            if(open_a > n/2 && open_b < n/2 && a[i] == '('){
                a[i] = ')';--open_a;
                b[i] = '(';++open_b;
            }
        }*/
        if(check(a) && check(b) && a!=b){
            cout<<"YES"<<endl;
            cout<<a<<endl;
            cout<<b<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
}