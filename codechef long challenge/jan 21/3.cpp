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
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int m[n];
        vector<int> x[n];
        f(i,0,n){
            cin>>m[i];
            x[i].resize(m[i]);
            f(j,0,m[i]) cin>>x[i][j];
        }
        if(n == 1){
            ll n1 = 0, n2 = 0;
            f(i,0,m[0]){
                if(x[0][i] >= 0) ++n1;
                else ++n2;
            }
            cout<<n1*n2<<endl;
        }
        else{
            map<int,vector<vector<int>>> dis;
            vector<int> n1(n),n2(n);
            f(i,0,n){
                f(j,0,m[i]){
                    if(x[i][j] < 0){
                        dis[abs(x[i][j])].pb({i,j,-1});
                        ++n1[i];
                    }
                    else{
                        dis[abs(x[i][j])].pb({i,j,1});
                        ++n2[i];
                    }
                }
            }

            ll ans = 0, ori = 0, turn = 0;
            for(auto it:dis){
                if(it.se.size() > 1){
                    ++ori;
                    for(auto &v: it.se){
                        int i = v[0], j = v[1], dir = v[2];
                        if(dir == -1){
                            n1[i]--;
                            turn += j;
                        }
                        else{
                            n2[i]--;
                            turn += m[i] - j - 1;
                        }
                    }
                    
                }
                else{
                    int i = it.se[0][0], j = it.se[0][1], dir = it.se[0][2];
                    ans += (dir == 1 ? n1[i] : n2[i]);
                    if(dir == -1) --n1[i];
                    else --n2[i];
                }
            }
            ll res = turn + ori + ans;
            cout<<res<<endl;
        }
    }
}