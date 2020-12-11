#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;

const ll mod = 1000000007;
const int maxn = 1e5;

class segtree{
public:
    vector<int> tree;
    segtree(int n){
        tree = vector<int>(4*n);
    }
    void build(int tn, int start, int end, vector<int> &arr){
        if(start == end){
            tree[tn] = arr[start];
            return;
        }
        int mid = (start + end)/2;
        build(2*tn,start,mid,arr);
        build(2*tn+1,mid+1,end,arr);
        tree[tn] = max(tree[2*tn],tree[2*tn+1]);
    }
    int query(int tn, int start, int end, int l, int r){
        if(start >= l && end <= r)
            return tree[tn];
        if(end < l || start > r)
            return -1;
        int mid = (start+end)/2;
        int a1 = query(2*tn,start,mid,l,r);
        int a2 = query(2*tn+1,mid+1,end,l,r);
        return max(a1,a2);
    }
};
vector<long long> xorProblem(int n, vector<int> a, int q, vector<vector<int>> queries) {
    vector<vector<int>> arr(n+1,vector<int>(n,-1));
    for(int i = 0; i < n; i++)
        arr[1][i] = a[i];

    for(int len = 1;len <= n; ++len){
        for(int i = 0; i + len <= n; i++){
            int j = i+ len - 1;
             if(len&1) arr[len][i] = (a[i] ^ a[j]);
            else{
                if(len == 2) 
                    arr[len][i] = (a[i] ^ a[j]);
                
                else
                    arr[len][i] = (arr[len-2][i]^a[j-1]^a[j]);
            }
        }
    }

    //for(int i = 0; i<n;i++) cout<<a[i]<<" "<<arr[2][i]<<endl;
    segtree *t[n+1];
    for(int i = 1; i <= n; i++){
        t[i] = new segtree(n);
        t[i]->build(1,0,n-1,arr[i]);
    }
    
    vector<long long> ans(q);
    for(int i = 0; i < q; i++){
        int l = queries[i][0], r = queries[i][1];
        --l;--r;
        long long res = 0;
        for(int len = 1;len <= r-l+1; ++len)
            res = max(res,1ll*t[len]->query(1,0,n-1,l,r-len+1));
        
        ans[i] = res;
    }
    return ans;
}

int main(){
    vector<int> a(6);
    for(int i = 0 ; i < 6; i++)
        a[i] = pow(2,i);
    vector<vector<int>> queries(4,vector<int>(2));
    queries[0] = {1,6};
    queries[1] = {2,5};
    queries[2] = {3,4};
    queries[3] = {1,2};
    vector<long long> ans = xorProblem(6,a,4,queries);
    for(auto x:ans) cout<<x<<endl;

}