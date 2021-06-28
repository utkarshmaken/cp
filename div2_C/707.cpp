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

/*void find(int ans[], vector<pii> &sum){
    f(i,0,4){
        int a = sum[i].fi, b = sum[i].se;
        f(j,0,4){
            int c = sum[j].fi, d = sum[j].se;
            if(a != c && a != d && b != c && b != d){
                ans[0] = a, ans[1] = b, ans[2] = c, ans[3] = d;
                return;
            }
        }
    }
    map<int,int> m;
    for(auto &p:sum){
        m[p.fi]++;
        m[p.se]++;
    }
    bool is4 = false;
    for(auto it:m)
        if(it.se == 4)
            is4 = true;
    if(is4){
        f(i,0,4)
            ans[i] = (m[sum[i].fi] == 4 ? sum[i].se : sum[i].fi);
        return;
    }
    f(i,0,4){
        int a = sum[i].fi, b = sum[i].se;
        if(m[a] != 3 && m[b] != 3){
            f(j,0,4){
                int c = sum[j].fi, d = sum[j].se;
                if(a != c && a != d && b != c && b != d){
                    ans[0] = a, ans[1] = b, ans[2] = c, ans[3] = d;
                    return;
                }
            }
        }
    }
    
}
int main(){
    int n,s;
    cin>>n;
    vector<int> arr(n);
    f(i,0,n) cin>>arr[i];
    vector<pii> sum[5000001];
    int  f = 0;
    int ans[4];
    f(i,0,n){
        f(j,i+1,n){
            s = arr[i] + arr[j];
            for(auto &p:sum[s]){
                int a = p.fi, b = p.se;
                if(a == i || a == j || b == i || b == j) continue;
                ans[0] = i, ans[1] = j, ans[2] = a, ans[3] = b;
                f = 1;                 
                break;
            }
            sum[s].pb({i,j});
            if(sz(sum[s]) == 4){
                f = 2;
                break;
            }
            if(f) break;
        }
        if(f) break;
    }
    if(f){
        if(f == 2) find(ans,sum[s]);
        cout<<"YES\n";
        f(_,0,4) cout<<1+ans[_]<<' ';
    }
    else
        cout<<"NO"<<endl;
}*/


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    f(i,0,n) cin>>arr[i];
    vector<pii> sum[5000005];
    f(i,1,n){
        f(j,0,n-i){
            int s = arr[j] + arr[j+i];
            for(auto &p:sum[s]){
               int a = p.fi, b = p.se;
               if(a != j && a != j+i && b != j && b != j+i){
                    cout<<"YES\n";
                    cout<<1+a<<' '<<1+b<<' '<<1+j<<' '<<1+i+j<<endl;
                    return 0;
               }
            }
            sum[s].pb({j,i+j});
        }
    }
    cout<<"NO"<<endl;
}