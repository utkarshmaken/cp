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
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(n == 2){
            cout<<-1<<endl;
            continue;
        }

        int ans[n][n];
        int num = 1;
        f(i,0,n)
            f(j,0,n)
                if((i+j) % 2 == 0)
                    ans[i][j] = num++;
        f(i,0,n)
            f(j,0,n)
                if((i+j) % 2 == 1)
                    ans[i][j] = num++;
        
        f(i,0,n)
            f(j,0,n)
                cout<<ans[i][j]<<" \n"[j==n-1];
    }

}