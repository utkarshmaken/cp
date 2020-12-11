//MULTIPLICATION OF BINARY NUMBERS
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
void add(string &a, string &b){
    int carry = 0;
    b+=string(sz(a)-sz(b),'0');
    f(i,0,sz(a)){
        int sum = carry + (a[i]-'0') + (b[i]-'0');
        a[i] = ('0' + sum%2);
        carry = sum/2;
    }
}
int main(){
    int A,B;
    cin>>A>>B;
    if(A<B) swap(A,B);
    string a = "",b = "";
    while(A!=0){
        int x = A&1;
        a += to_string(x);
        A = A>>1;
    }
    while(B!=0){
        int x = B&1;
        b += to_string(x);
        B = B>>1;
    }
    string ans = string(sz(a)*sz(b),'0');
    cout<<a<<' '<<b<<' '<<ans<<endl;
    f(i,0,sz(b)){
        string s = string(i,'0');
        if(b[i] == '0') s+=string(sz(a),'0');
        else s+=a;
        add(ans,s);
    }
    
    int digits = 0;
    for(auto &x:ans)
        if(x == '1')
            ++digits;
    cout<<digits<<endl;
}
