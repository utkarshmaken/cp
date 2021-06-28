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

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        vector<int> avail[m];
        f(i,0,m){
            int k;
            cin>>k;
            avail[i] = vector<int>(k);
            f(j,0,k)
                cin>>avail[i][j];
        }

        vector<int> ans(m);
        vector<int> freq(n+1);
        f(i,0,m){
            ans[i] = avail[i][0];
            freq[ans[i]]++;
        }

        rep(v,1,n){
            if(freq[v] > (m+1)/2){
                for(int i = 0; i < m && freq[v] > (m+1)/2; i++){
                    if(ans[i] == v && sz(avail[i]) > 1){
                        ans[i] = avail[i][1];
                        --freq[v];
                        ++freq[avail[i][1]];
                    }
                }
                if(freq[v] > (m+1)/2){
                    cout<<"NO"<<endl;
                    goto finished;
                }
            }
        }

        cout<<"YES"<<endl;
        f(i,0,m) cout<<ans[i]<<" \n"[i == m-1];

finished:;
    }
        
}