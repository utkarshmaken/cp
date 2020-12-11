//
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
    int n,k;cin>>n>>k;
    string s;cin>>s;
    stack<pair<char,int>> stk;
    f(i,0,n){
        char ch = s[i];
        if(stk.empty() || stk.top().first!=ch)
            stk.push({ch,1});
        else{
            int count = stk.top().second + 1;
            stk.pop();
            stk.push({ch,count%k});
        }
    }
    string ans = "";
    while(!stk.empty()){
        char ch = stk.top().first,len = stk.top().second;
        ans+=string(len,ch);
        stk.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;





    
}