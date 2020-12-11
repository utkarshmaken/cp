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
const int maxn = 200000;
 
int main(){
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       if(n==36){
           cout<<"YES"<<endl;
           cout<<"5 6 10 15"<<endl;
           continue;
        }
        if(n==40){
            cout<<"YES" <<endl;
            cout<<"5 6 14 15"<<endl;
            continue;
        }
        if(n==44){
            cout<<"YES" <<endl;
            cout<<"6 10 13 15"<<endl;
            continue;
        }

       if(n> 6 + 10 + 14){
            cout<<"YES" <<endl;
            cout<<"6 10 14 "<<n-30<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

}