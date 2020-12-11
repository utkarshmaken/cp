//SORTED ARRANGEMENT
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

class BIT{
public:
    vector<int> tree;
    int maxIndex;
    BIT(int n){
        tree = vector<int>(n+1);
        maxIndex = n;
    }
    void update(int idx, int val){
        while(idx <= maxIndex){
            tree[idx]+=val;
            idx+=(idx&(-idx));
        }
    }
    int get(int idx){
        int sum = 0;
        while(idx > 0){
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
    const int maxn = 1e5;
    BIT t(maxn);
    int ans = 0;
    f(i,0,n){
        int x = arr[i];
        int a1 = t.get(x-1);
        int a2 = i - (t.get(x));
        ans+= 1 + 2*min(a1,a2);
        t.update(x,1); 
    }
    cout<<ans<<endl;
}