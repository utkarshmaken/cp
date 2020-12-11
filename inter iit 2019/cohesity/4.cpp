//MINIMUM FUEL COST
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
class SegTree{
public:
    vector<int> tree;
    SegTree(int n){
        tree = vector<int>(4*n,INT_MAX);
    }
    void update(int tn, int idx, int val, int s, int e){
        if(s == e){
            tree[tn] = val;
            return;
        }
        int mid = (s+e)/2;
        if(idx<=mid) update(2*tn,idx,val,s,mid);
        else update(2*tn+1,idx,val,mid+1,e);
        tree[tn] = min(tree[2*tn], tree[2*tn+1]);
    }
    int query(int tn, int l, int r, int s, int e){
        if(l<=s && e<=r) return tree[tn];
        if(s>r || e<l) return INT_MAX;
        int mid = (s+e)/2;
        int a1 = query(2*tn,l,r,s,mid);
        int a2 = query(2*tn+1,l,r,mid+1,e);
        return min(a1,a2);
    }
};
int main(){
    int c_init;cin>>c_init;
    int n;cin>>n;
    vector<int> pos(n),cost(n),c(n);
    f(i,0,n) cin>>pos[i];
    f(i,0,n) cin>>cost[i];
    f(i,0,n) cin>>c[i];
    int d;cin>>d;
    vector<int> dp(n);
    SegTree seg(n);
    dp[n-1] = c[n-1];
    seg.update(1,n-1,dp[n-1],0,n-1);
    repd(i,n-2,0){
        int reach = pos[i] + c[i];
        if(reach>=d)
            dp[i] = cost[i];
        else{
            auto it = upper_bound(all(pos),reach);
            --it;
            int idx = it - pos.begin();
            if(idx==i) dp[i] = INT_MAX;
            else{
                dp[i] = cost[i] + seg.query(1,i+1,idx,0,n-1);
            }
        }
        seg.update(1,i,dp[i],0,n-1);
    }
    auto it = upper_bound(all(pos),c_init);
    --it;
    int idx = it - pos.begin();
    int ans = seg.query(1,0,idx,0,n-1);
    cout<<ans<<endl;
}