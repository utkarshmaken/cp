//SUBMATRIX MAXIMUM
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
const int maxn = 1e5;

int main(){
    int t;cin>>t;
    while(t--){
        int n,k,m;
        cin>>n>>k>>m;
        int grid[n][n];
        f(i,0,n) f(j,0,n) cin>>grid[i][j];
        vector<int> arr;
        f(i,0,n){
            deque<int> q;
            vector<int> maxi;
            f(j,0,n){
                while(!q.empty() && q.front() <= j-k)
                    q.pop_front();
                while(!q.empty() && grid[i][j] >= grid[i][q.back()])
                    q.pop_back();
                q.push_back(j);
                if(j>=k-1)
                    maxi.push_back(grid[i][q.front()]);
            }
            f(j,k-1,n) grid[i][j] = maxi[j-k+1];
        }
        f(j,k-1,n){
            deque<int> q;
            vector<int> maxi;
            f(i,0,n){
                while(!q.empty() && q.front() <= i-k)
                    q.pop_front();
                while(!q.empty() && grid[i][j] >= grid[q.back()][j])
                    q.pop_back();
                q.push_back(i);
                if(i>=k-1)
                    maxi.push_back(grid[q.front()][j]);
            }
            f(i,k-1,n) grid[i][j] = maxi[i-k+1];
        }
        f(i,k-1,n)
            f(j,k-1,n)
                arr.pb(grid[i][j]);
        sort(all(arr));
        int idx = lower_bound(all(arr),m) - arr.begin();
        int a1 = sz(arr)-idx;
        int a2 = arr[idx];
        int a3 = arr.back();
        cout<<a1<<" "<<a2<<" "<<a3<<endl;

    }
}