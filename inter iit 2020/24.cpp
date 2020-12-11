//DIVIDE THEM ALL
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
    int n,m;
    cin>>n>>m;
    int grid [n][m];
    f(i,0,n) f(j,0,m) cin>>grid[i][j];
    vector<int> avail(n);
    f(i,0,n)
        f(j,0,m)
            if(grid[i][j]!=1) avail[i]+=1;
    multiset<int> s;
    for(auto &x:avail)
        if(x!=0)
            s.insert(x);
    int len = s.size();
    int turn = 1;
    while(len>0){
        cout<<len<<' '<<turn<<endl;
        if(len&1){
            s.erase(--s.end());
            --len;
        }
        else{
            auto it = (--s.end());
            if(*it > 1){
                s.erase(it);
                s.insert(1);
            }
            else
            {
               s.erase(it);
               --len;
            }
        }
        turn  = 1-turn;
    }
    if(turn == 1) cout<<2<<endl;
    else cout<<1<<endl;
}