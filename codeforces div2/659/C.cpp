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
        string a,b;
        cin>>a>>b;
        char ch = 'a';
        int ans = 0;
        f(i,0,20){
            char smallest = 'z';
            f(j,0,n){
                if(a[j] == ch+i && a[j]!=b[j])
                    smallest = min(smallest,b[j]);
            }
            if(smallest=='z') 
                continue;
            else if(smallest<=ch+i){
                ans = -1;
                break;
            }
            else{
                f(j,0,n)
                    if(a[j]==ch+i && a[j]!=b[j])
                        a[j] = smallest;
                ans++;
            }
        }
        cout<<ans<<endl;

    }

}