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
int n;
bool poss(vector<int> &a, int &val, int &len){
    int prev = a[0],taken = 1;
    f(i,1,n){
        if(a[i]-prev>=val){
            ++taken;
            prev = a[i];
        }
    }
    return taken>=len;

}
int main(){
    cin>>n;
    vector<int> a(n);
    f(i,0,n) cin>>a[i];
    sort(all(a));
    int len;cin>>len;
    int low = INT_MAX,high = a[n-1]-a[0];
    f(i,0,n-1) low = min(low,a[i+1]-a[i]);
    int ans;
    while(low<=high){
        int mid = (low+high)/2;
        if(poss(a,mid,len)){
            ans = mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }
    cout<<ans<<endl;
}