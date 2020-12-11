//WELLS FARGO LONGEST PREFIX ROTATE STRING
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
    string s;string t;
    cin>>s>>t;
    int n = sz(s);
    int len = 0,rotate = 0;
    rep(i,0,n-1){
        int start = i;
        int comm = 0;
        while(start<n && s[comm] == t[start]){
            ++comm;++start;
        }
        if(start == n){
            start = 0;
            while(start<i && s[comm] == t[start]){
                ++comm;++start;
            }
        }
        if(comm > len){
            len = comm;
            rotate = min(i,n-i);
        }
        else if(comm == len){
            rotate = min(rotate,min(i,n-i));
        }
    }
    cout<<rotate<<endl;
}