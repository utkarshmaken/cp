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

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        vector<pii> arr(n);
        f(i,0,n) cin>>v[i],arr[i] = {v[i],i};
        sort(all(arr));
        int j = 0;
        f(i,0,n){
            if(i>0 && arr[i].fi!=arr[i-1].fi)
                j++;
            v[arr[i].se] = j;
        }

        unordered_map<int,set<int>> m;
        f(i,0,n) m[v[i]].insert(i);
        vector<int> dp(n,0);
        int maxi = 0;
        f(i,0,n){
            int num = v[i];
            if(num==0 || *m[num-1].begin()>i)
                dp[i] = 1 + distance(m[num].begin(),m[num].find(i));
            else{
                int i1  = *(--m[num-1].lower_bound(i));
                int i2 =  m[num].find(i)!=m[num].begin()?*(--m[num].find(i)):i;
                dp[i] = 1+ max(dp[i1],dp[i2]);
            }
            maxi = max(maxi,dp[i]);
            cout<<dp[i]<<' ';
        }
        cout<<endl;
        f(i,0,n) cout<<v[i]<<' ';
       // cout<<n - maxi<<endl;



        
    }

}