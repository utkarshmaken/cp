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
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        if(y>=2*x || (n==1 && m==1))
            cout<<n*m*x<<endl;
        else{
            if(m&1){
                int candies = 0;
                if(y<=x)
                    candies = (n/2)*m*y + (n%2)*(m+1)*y/2;
                else
                    candies = (n/2)*m*y + (n%2)*((m-1)*y/2 + x);
                cout<<candies<<endl;
            }
            else{
                int candies = n * (m/2)*y;
                cout<<candies<<endl;
            } 
        }

    }

}