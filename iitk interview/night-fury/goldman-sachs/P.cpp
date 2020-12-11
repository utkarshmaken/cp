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
    string s;
    cin>>s;
    int n = sz(s);
    int i = 0,j = n-1;
    while(i<j){
        if(s[i] == s[j]){
            int i1 = i,j1 = j;
            rep(k,i,j-1){
                if(s[i] == s[k]) i1 = k;
                else break;
            }
            repd(k,j,i1+1){
                if(s[j] == s[k]) j1 = k;
                else break;
            }
            i = i1+1;j = j1-1;
        }
        else
            break;
    }
    cout<<max(0,j-i+1)<<endl;




}