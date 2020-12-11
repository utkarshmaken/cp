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
#define mp make_pair
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
#define endl '\n'
using namespace std;
const int mod = 1000000007;
const int maxn = 200001;
vector<int> take(maxn),tree(4*maxn);
void build(int tn, int start, int end){
    if(start==end){
        tree[tn] = take[start];
        return;
    }
    int mid = (start+end)/2;
    build(2*tn,start,mid);
    build(2*tn+1,mid+1,end);
    tree[tn] = max(tree[2*tn],tree[2*tn+1]);
}
int query(int tn, int l, int r, int start, int end){
    if(start>r || end<l) return -1;
    if(l<=start && end<=r) return tree[tn];
    int mid = (start+end)/2;
    int a1 = query(2*tn,l,r,start,mid);
    int a2 = query(2*tn+1,l,r,mid+1,end);
    return max(a1,a2);
}
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<pii> pos(n);
        f(i,0,n) cin>>pos[i].fi;
        f(i,0,n) cin>>pos[i].se;
        sort(all(pos));
        
        f(i,0,n){
            int x = pos[i].fi;
            auto it = upper_bound(all(pos),mp(x+k,INT_MAX));
            if(it!=pos.begin()){
                --it;
                int idx = it-pos.begin();
                int num = idx-i+1;
                take[i] = num;
            }
        }
        build(1,0,n-1);
        int maxi = 0;
        f(i,0,n){
            int a1 = take[i];
            int idx = i+a1-1;
            int a2 = idx+1>=n?0:query(1,idx+1,n-1,0,n-1);
            maxi =max(maxi,a1+a2);

        }
        cout<<maxi<<endl;


    }

}