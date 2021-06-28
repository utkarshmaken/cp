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

bool allequal(vector<int> arr){
    if(sz(arr) == 1)
        return true;
    f(i,1,sz(arr))
        if(arr[i] != arr[i-1])
            return false;
    return true;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> john(n);
        vector<int> jack(m);
        ll s_john = 0, s_jack = 0;
        f(i,0,n) cin>>john[i], s_john += john[i];
        f(i,0,m) cin>>jack[i], s_jack += jack[i];
        if(s_john > s_jack){
            cout<<0<<endl;
            continue;
        }
        if(allequal(john) && allequal(jack) && john[0] == jack[0]){
            cout<<(n <= m ? -1 : 0)<<endl;
            continue;
        }
        multiset<int> jo,ja;
        f(i,0,n) jo.insert(john[i]);
        f(i,0,m) ja.insert(jack[i]);
        int ans = 0;
        while(s_john <= s_jack && *jo.begin() < *(--ja.end())){
            int less = *jo.begin(), more = *(--ja.end());
            s_john += more - less;
            s_jack -= more - less;
            jo.erase(jo.begin());jo.insert(more);
            ja.erase(--ja.end());ja.insert(less);
            ++ans;
        }
        if(s_john <= s_jack)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
}