//GAME WINNER
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
const int maxn = 1e5;

int main(){
    string s;cin>>s;
    int n = sz(s);
    int w = 0,b = 0;
    f(i,0,n-2){
        if(s[i] == 'w' && s[i+1] == 'w' && s[i+2] =='w'){
            if((i==0 || s[i-1] == 'b') && (i+3 == n || s[i+3] == 'b'))
                ++w;
        }
        else if(s[i] == 'b' && s[i+1] == 'b' && s[i+2] =='b'){
            if((i==0 || s[i-1] == 'w') && (i+3 == n || s[i+3] == 'w'))
                ++b;
        }
    }
    if(w<=b) cout<<"Bob"<<endl;
    else cout<<"Wendy"<<endl;

}
