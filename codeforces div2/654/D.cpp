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
#define mp make_pair
#define pb push_back
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
using namespace std;
const int mod = 1000000007;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> A(n,vector<int>(n,0));
        int r = k%n;
        if(r == 0)
            cout<<0<<endl;
        else
            cout<<2<<endl;
        int i = 0,j = 0;
        rep(_,1,k){
            A[i][j] = 1;
            i = (i+1)%n;
            j = (j+1);
            if(j==n){
                j=0;
                i = (i+1)%n;
            }
        }
        f(i,0,n){
            f(j,0,n)
                cout<<A[i][j];
            cout<<endl;
        }

        
        
    }
}