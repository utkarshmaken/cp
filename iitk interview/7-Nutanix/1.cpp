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
#define mp make_pair
#define pb push_back
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
using namespace std;
const int mod = 1000000007;
const int maxn = 1e5+5;

int main(){
    int n;
    cin>>n;
    vector<int> color(n);
    f(i,0,n) cin>>color[i];
    unordered_map<int,int> last;
    unordered_map<int,int> num;
    f(i,0,n){
        last[color[i]] = i;
        num[color[i]]+=1;
    }
    int cost = 0;
    int start = 0,max_last = last[color[0]];
    set<int> s;
    f(i,0,n){
       max_last = max(max_last,last[color[i]]);
       s.insert(color[i]);
       if(max_last == i){
           int maxi = 0;
           for(auto c:s)
            maxi = max(maxi,num[c]);
           cost+= (max_last-start+1) - maxi;
           start = max_last+1;
           s.clear();
        }

    }
    cout<<cost<<endl;

}