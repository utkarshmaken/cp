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
const int maxn = 100001;

int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    repd(i,y,1) cout<<x<<' '<<i<<endl;
    rep(i,y+1,m) cout<<x<<' '<<i<<endl;
    repd(i,x-1,1) cout<<i<<' '<<m<<endl;
    rep(i,x+1,n) cout<<i<<' '<<m<<endl;
    int start = n,col = m-1;
    while(col!=0){
        if(start==n){
            repd(i,n,1)
                if(i!=x) cout<<i<<' '<<col<<endl;
            col--;
            start=1;
        }
        else if(start==1){
            rep(i,1,n)
                if(i!=x) cout<<i<<' '<<col<<endl;
            col--;
            start=n;
        }
    }
    
}