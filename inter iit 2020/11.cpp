//SORTED ARRANGEMENT
//USE OF BINARY INDEXED TREE
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
    int n;
    BIT(int n){
        tree = vector<int>(n);
        this->n = n;
    }
    void update(int idx, int val){
        while(idx < n){
            tree[idx]+=val;
            idx+= (idx & (-idx));
        }
    }
    int get(int idx){
        int sum = 0;
        while(idx > 0){
            sum+=tree[idx];
            idx-= (idx & (-idx));
        }
        return sum;
    }

};
int main(){
    int n;cin>>n;
    vector<int> arr(n);
    f(i,0,n) cin>>arr[i];
    int ans = 0;
    BIT b(maxn);
    f(i,0,n){
        int x = arr[i];
        int left = b.get(x-1);
        int right = i - b.get(x);
        ans+= 1+2*min(left,right);
        b.update(x,1);
    }
    cout<<ans<<endl;


}
