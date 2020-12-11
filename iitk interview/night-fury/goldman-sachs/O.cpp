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
    string s,t;
    cin>>s>>t;
    int n = s.size(),m = t.size();
    int i = 0,j = 0,star = 0,prev =-1,j0;
    bool poss = true;
    while(i<m || j<n){
        if((i<m && j<n) && (t[i] == s[j] || t[i] == '$')){
            ++i;++j;
            continue;
        }
        if((i<m && j<n) && t[i] == '@'){
            star = 1;
            prev = i;
            j0 = ++j;
            i++;
            continue;
        }
        if(star == 1){
            i = prev+1;
            j = ++j0;
            continue;
        }
        poss = false;
        break;
    }
    
    if(poss){
        while(i<m && t[i]=='@') ++i;
        if(i!=m) poss = false;
    }

    if(poss) cout<<"True"<<endl;
    else cout<<"False"<<endl;

}