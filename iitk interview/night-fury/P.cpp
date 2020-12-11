//SHOPPER'S DELIGHT
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
vector<int> items[4];
int main(){
    int a,b,c,d;
    cin>>a;
    items[0] = vector<int>(a);
    f(i,0,a) cin>>items[0][i];
    cin>>b;
    items[1] = vector<int>(b);
    f(i,0,b) cin>>items[1][i];
    cin>>c;
    items[2] = vector<int>(c);
    f(i,0,c) cin>>items[2][i];
    cin>>d;
    items[3] = vector<int>(d);
    f(i,0,d) cin>>items[3][i];
    int amt;cin>>amt;
    unordered_map<int,int> dp;
    for(auto x:items[0]) if(x<=amt) dp[x]+=1;
    for(int i =1;i<4;i++){
        unordered_map<int,int> ndp;
        for(auto it:dp){
            for(auto x:items[i]){
                if(it.first + x <= amt)
                    ndp[it.first + x]+= it.second;
            }
        }
        dp = ndp;
    }
    int ans = 0;
    for(auto it:dp) ans+=it.second;
    cout<<ans<<endl; 

}