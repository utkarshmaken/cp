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

/*int find(vector<int> &arr, int &n, int &x, int &y){
    vector<int> a(n);
    f(i,0,n) a[i] = arr[i];
    sort(all(a));
    vector<int> sum(n);
    sum[0] = arr[0];
    f(i,1,n) sum[i] = sum[i-1] + arr[i];
    auto it = lower_bound(all(sum),x);
    if(it != sum.end() && *it <= y)
        return 0;
    else{
        multiset<int> s;
        f(i,1,n) s.insert(arr[i]);
        f(i,0,n-1){
            rep(j,0,i){
                ll curr = sum[i] - arr[j];
                auto it = s.lower_bound(x - curr);
                if(it != s.end() && *it + curr <= y)
                    return 1;
            }
            s.erase(s.find(arr[i+1]));
        }
        return 2;
    }  
}*/

int find(vector<int> &arr, int i, int &n, int &x, int &y, int curr){
    if(curr >= x && curr <= y) return 0;
    if(i >= n) return INT_MAX;
    int a1 = find(arr,i+1,n,x,y,curr+arr[i]);
    int a2 = INT_MAX;
    f(j,i+1,n){
        int a = find(arr,i+1,j,x,y,curr+arr[j]);
        if(a != INT_MAX)
            a2 = min(a2,1+a);
    }
    return min(a1,a2);
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        vector<int> arr(n);
        f(i,0,n) cin>>arr[i];
        int ans = find(arr,0,n,x,y,0);
        cout<<(ans == INT_MAX ? -1 : ans)<<endl;
    }
}