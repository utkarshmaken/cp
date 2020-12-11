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
using namespace std;
const int mod = 1000000007;
const int maxn = 2000000;
int main(){
    string s;
    cin>>s;
    int n = sz(s);
    int w  = 0,b = 0;
    int i = 0;
    while(i<n){
        int j = i;
        while(j<n && s[j]==s[i])
            j++;
        if(j-i>=3){
            if(s[i]=='b') b+=j-i-2;
            else w+=j-i-2;
        }
        i = j;
    }
    if(w<=b) cout<<"bob"<<endl;
    else cout<<"wendy"<<endl;

}