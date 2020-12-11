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
using namespace std;
const int mod = 1000000007;
const int maxn = 1000001;
int tree_lr[4*maxn],tree_rl[4*maxn];
vector<int> h(maxn),a(maxn),arr_lr,arr_rl;
vector<int> adj_lr[maxn],adj_rl[maxn];

void dfs1(int u, int pu){
    arr_lr.pb(u);
    for(auto v:adj_lr[u])
        if(v!=pu)
            dfs1(v,u);
    arr_lr.pb(u);
}
void dfs2(int u, int pu){
    arr_rl.pb(u);
    for(auto v:adj_rl[u])
        if(v!=pu)
            dfs2(v,u);
    arr_rl.pb(u);
}
void buildTree1(int tn, int start, int end){
    if(start==end){
        tree_lr[tn] = a[arr_lr[start]];
        return;
    }
    int mid = (start+end)/2;
    buildTree1(2*tn,start,mid);
    buildTree1(2*tn+1,mid+1,end);
    tree_lr[tn] = tree_lr[2*tn] + tree_lr[2*tn+1];
}
void buildTree2(int tn, int start, int end){
    if(start==end){
        tree_rl[tn] = a[arr_rl[start]];
        return;
    }
    int mid = (start+end)/2;
    buildTree2(2*tn,start,mid);
    buildTree2(2*tn+1,mid+1,end);
    tree_rl[tn] = tree_rl[2*tn] + tree_rl[2*tn+1];
}
void update1(int idx, int val, int tn, int start, int end){
    if(start==end){
        tree_lr[tn] =  val;
        return;
    }
    int mid = (start+end)/2;
    if(idx<=mid)
        update1(idx,val,2*tn,start,mid);
    else
        update1(idx,val,2*tn+1,mid+1,end);
    tree_lr[tn] = tree_lr[2*tn] + tree_lr[2*tn+1];
}
void update2(int idx, int val, int tn, int start, int end){
    if(start==end){
        tree_rl[tn] =  val;
        return;
    }
    int mid = (start+end)/2;
    if(idx<=mid)
        update2(idx,val,2*tn,start,mid);
    else
        update2(idx,val,2*tn+1,mid+1,end);
    tree_rl[tn] = tree_rl[2*tn] + tree_rl[2*tn+1];
}
ll query1(int tn, int l, int r, int start, int end){
    if(start > r || end < l)
        return 0ll;
    if(l<=start && end<=r)
        return tree_lr[tn];
    int mid = (start+end)/2;
    ll a1 = query1(2*tn,l,r,start,mid);
    ll a2 = query1(2*tn+1,l,r,mid+1,end);
    return a1+a2;
}
ll query2(int tn, int l, int r, int start, int end){
    if(start > r || end < l)
        return 0ll;
    if(l<=start && end<=r)
        return tree_rl[tn];
    int mid = (start+end)/2;
    ll a1 = query2(2*tn,l,r,start,mid);
    ll a2 = query2(2*tn+1,l,r,mid+1,end);
    return a1+a2;
}


int main(){
    int n,q;
    cin>>n>>q;
    rep(i,1,n) cin>>h[i];
    rep(i,1,n) cin>>a[i];
    vector<int> lr(n+1,-1),rl(n+1,-1);
    stack<int> s;
    s.push(1);
    for(int i = 2;i<=n;i++){
        while(!s.empty() && h[s.top()]<h[i])
            s.pop();
        if(!s.empty())
            lr[i] = s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    s.push(n);
    for(int i = n-1;i>=1;i--){
        while(!s.empty() && h[s.top()] < h[i])
            s.pop();
        if(!s.empty())
            rl[i] = s.top();
        s.push(i);
    }
    
    rep(i,1,n){
        int v = i,u = lr[i];
        if(u!=-1){
            adj_lr[u].pb(v);
            adj_lr[v].pb(u);
        }
        else{
            adj_lr[0].pb(v);
            adj_lr[v].pb(0);
        }
    }
    rep(i,1,n){
        int v = i,u = rl[i];
        if(u!=-1){
            adj_rl[u].pb(v);
            adj_rl[v].pb(u);
        }
        else{
            adj_rl[0].pb(v);
            adj_rl[v].pb(0);
        }
    }

    dfs1(0,-1);dfs2(0,-1);
    cout<<endl;
    for(auto x:arr_lr) cout<<x<<' ';
    cout<<endl;
    for(auto x:arr_rl) cout<<x<<' ';
    buildTree1(1,0,2*n+1);buildTree2(1,0,2*n+1);
    vector<pii> idx1(n+1),idx2(n+1);
    f(i,0,2*n+2){
        if(idx1[arr_lr[i]].fi==0)
            idx1[arr_lr[i]].fi = i;
        else
            idx1[arr_lr[i]].se = i;
    }
    f(i,0,2*n+2){
        if(idx2[arr_rl[i]].fi==0)
            idx2[arr_rl[i]].fi = i;
        else
            idx2[arr_rl[i]].se = i;
    }
    cout<<endl;
    rep(i,0,n) cout<<idx1[i].fi<<' '<<idx1[i].se<<endl;
    rep(i,0,n) cout<<idx2[i].fi<<' '<<idx2[i].se<<endl;

    f(i,0,q){
        int type;cin>>type;
        if(type==1){
            int b,k;cin>>b,k;
            update1(idx1[b].fi,k,1,0,2*n+1);
            update1(idx1[b].se,k,1,0,2*n+1);
            update2(idx2[b].fi,k,1,0,2*n+1);
            update2(idx2[b].se,k,1,0,2*n+1);

        }
        else if(type==2){
            int b,c;cin>>b>>c;
            if(b==c) cout<<a[b]<<endl;
            else if(b<c){
               if(idx1[b].fi < idx1[c].fi && idx1[c].se < idx1[b].se)
                    cout<<(query1(1,idx1[b].fi,idx1[b].se,0,2*n+1) - query1(1,idx1[c].fi,idx1[c].se,0,2*n+1))/2 + a[c]<<endl;
                else
                    cout<<-1<<endl;
            }
            else{
                if(idx2[b].fi < idx2[c].fi && idx2[c].se < idx2[b].se)
                    cout<<(query2(1,idx2[b].fi,idx2[b].se,0,2*n+1) - query2(1,idx2[c].fi,idx2[c].se,0,2*n+1))/2 + a[c]<<endl;
                else
                    cout<<-1<<endl;
            }
        }
    }

}