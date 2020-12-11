//INFIX TO POSTFIX
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
    string infix;cin>>infix;
    stack<char> s;
    string ans = "";
    int n = infix.size();
    map<char,int> m;
    m['*'] = 2;m['/'] = 2;m['+'] = 1;m['-'] = 1;

    int i = 0;
    while(i<n){
        char ch = infix[i];
        if(ch>='a' && ch<='z')
            ans+=ch;
        else{
            while(!s.empty() && m[s.top()]>=m[ch]){
                ans+=s.top();
                s.pop();
            }
            s.push(ch);
        }
        ++i;
    }
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    cout<<ans<<endl;
}