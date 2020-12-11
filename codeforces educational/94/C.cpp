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
       string s;cin>>s;
       int n = sz(s);
       int x;cin>>x;
       string w(n,'1');
       int f = 0;
       f(i,0,n){
           if(s[i]=='0'){
               if(i-x>=0) w[i-x] = '0';
               if(i+x<n) w[i+x] = '0';
           }
       }
       f(i,0,n){
           if(s[i]=='1'){
               if(i-x<0 && i+x>=n) f=1;
               else if(i-x<0 && w[i+x]=='0') f=1;
               else if(i+x>=n && w[i-x]=='0') f=1;
               else if(w[i-x]=='0' && w[i+x]=='0') f=1;
            }
            if(f) break;
       }
       if(f) cout<<-1<<endl;
       else cout<<w<<endl;
    }

}