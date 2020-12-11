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
const int maxn = 100000;
bool compare(pair<pii,int> a,pair<pii,int> b){
    if(a.fi.fi == b.fi.fi){
        return a.se > b.se;
    }
    return a.fi.fi < b.fi.fi;
}
vector<int> loadBalancing(int k, int n, vector<int> arr, vector<int> load){
    vector<pair<pii,int>> time(2*n);
    f(i,0,n){
        time[i] = {{arr[i],i},1};
        time[i+n] = {{arr[i]+load[i]-1,i},-1};
    }
    sort(all(time),compare);
    vector<int> work(k+1,0);
    unordered_map<int,int> server;
    set<int> avail;
    rep(i,1,k) avail.insert(i);
    int index = 0;
    f(i,0,2*n){
        pair<pii,int> curr = time[i];
        if(curr.se == -1){
            int s = server[curr.fi.se];
            if(s!=0)
                avail.insert(s);
                
        }
        else{
             if(!avail.empty()){
                auto it = avail.upper_bound(index);
                int s;
                if(it == avail.end())
                    s = *avail.begin();
                else
                    s = *it;
                work[s] += load[curr.fi.se];
                server[curr.fi.se] = s;
                avail.erase(s);
                index = s;
            }
        }
    }
   
    int maxi = INT_MIN;
    rep(i,1,k)
        if(work[i]>maxi)
            maxi = work[i];
    vector<int> ans;
    rep(i,1,k)
        if(work[i] == maxi)
            ans.pb(i);
    return ans;


}
int main(){
    int n,k;
    cin>>k>>n;
    vector<int> arr(n),load(n);
    f(i,0,n) cin>>arr[i];
    cin>>n;
    f(i,0,n) cin>>load[i];
    vector<int> ans = loadBalancing(k,n,arr,load);
    for(auto i:ans)
        cout<<i<<endl;

}