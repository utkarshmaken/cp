//SELLING PRODUCTS
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
    int n;cin>>n;
    map<int,int> freq;
    f(i,0,n){
        int x;cin>>x;
        freq[x]+=1;
    }
    multiset<int> s;
    for(auto it:freq) s.insert(it.second);
    int m;cin>>m;
    int ans = 0;
    for(auto x:s){
        if(m > 0){
            if(x >m){
                ++ans;m = 0;
            }
            else{
                m-=x;
            }
        }
        else ++ans;
    }
    cout<<ans<<endl;


}