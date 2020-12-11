//PETER PARKER WALL JUMP
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
    int n;
    cin>>n;
    vector<int> arr(n);
    f(i,0,n) cin>>arr[i];
    int c,f;
    cin>>c>>f;
    int ans = 0;
    f(i,0,n){
        if(i!=n-1){
            if(i%2==0) ans+=(i+1);
            else ans-=(i+1);
        }
        int h = arr[i];
        int jump;
        if(c>=h) jump = 1;
        else{
            jump = (h-c)/(c-f);
            if(jump*(c-f) < (h-c)) ++jump;
            ++jump;
        }
        ans+=jump;
    }
    cout<<ans<<endl;

}