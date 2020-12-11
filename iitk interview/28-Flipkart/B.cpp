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
const int maxn = 200000;
int main(){
    int n;
    scanf("%d",&n);
    scanf("%d",&n);
    int arr[n][n];
    f(i,0,n) f(j,0,n) scanf("%d",&arr[i][j]);
    int max_sum; 
    scanf("%d",&max_sum);
    ll sum[n+1][n+1];
    rep(i,0,n){
        rep(j,0,n){
            if(i==0 || j==0)
                sum[i][j] = 0;
            else
                sum[i][j] = arr[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];   
        }
    }
    int low = 1,high = n;
    while(low<=high){
        int mid = (low+high)/2;
        bool flag = true;
        rep(i,1,n){
            rep(j,1,n){
                if(i+mid-1>n || j+mid-1>n) break;
                ll subsum = sum[i+mid-1][j+mid-1] + sum[i-1][j-1]
                            -sum[i-1][j+mid-1] -sum[i+mid-1][j-1];
                if(subsum > max_sum){
                    flag = false;
                    break;
                }

            }
            if(!flag) break;
        }
        if(flag) low = mid+1;
        else high = mid-1;
    }
    cout<<low-1<<endl;

}