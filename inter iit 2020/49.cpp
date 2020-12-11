//BULB COUNT
//USES BIT
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
class BIT{
public:
    vector<int> tree;
    int maxIndex;
    BIT(int n){
        tree = vector<int>(n,0);
        maxIndex = n-1;
    }
    void update(int idx, int val){
        while(idx<=maxIndex){
            tree[idx]+=val;
            idx+=(idx&(-idx));
        }
    }
    int get(int idx){
        int sum = 0;
        while(idx >0){
            sum+=tree[idx];
            idx-=(idx&(-idx));
        }
        return sum;
    }
};
int main(){
    int n;cin>>n;
    vector<int> arr(n);
    f(i,0,n) cin>>arr[i];
    BIT t(n+1);
    int ans = 0,maxi = 0;
    f(i,0,n){
        int val = arr[i];
        t.update(val,1);
        maxi = max(maxi,arr[i]);
        int s = t.get(maxi);
        if(s == maxi) ++ans;
    }
    cout<<ans<<endl;
}