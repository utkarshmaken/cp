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
using namespace std;
const int mod = 1000000007;
const int maxn = 100001;
int main(){
    int n;
    cin>>n;
    vector<int> cost(n);
    f(i,0,n) cin>>cost[i];
    int money;
    cin>>money;
    int start = 0;
    int ans = 0,sum = 0;
    f(i,0,n){
        if(sum+cost[i]<=money){
            sum+=cost[i];
            continue;
        }
        ans = max(ans,i-start);
        sum+=cost[i];
        while(sum>money)
            sum-=cost[start++];
    }
    ans = max(ans,i-start);
    cout<<ans<<endl;

}
/*int main(){
    int n;
    cin>>n;
    vector<int> cost(n);
    f(i,0,n) cin>>cost[i];
    int money;
    cin>>money;
    vector<int> sum(n+1);
    f(i,0,n) sum[i+1] = sum[i] + cost[i];
    int ans = 0;
    f(i,0,n){
        if(cost[i]>money) continue;
        auto it = upper_bound(all(sum),sum[i]+money);
        if(it==sum.end()) ans = max(ans,n-i);
        else{
            int j =it-sum.begin();
            ans = max(ans,j-i-1);
        }
    }
    cout<<ans<<endl;

}*/