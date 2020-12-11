//MINIMUM DIVISOR
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
bool poss(vector<int> &a, int &thres, int div){
    ll s = 0;
    for(auto &x:a)
        s+=ceil((1.0*x)/div);
    return s<=thres;
}
int main(){
    int n;cin>>n;
    vector<int> a(n);
    f(i,0,n) cin>>a[i];
    int thres;cin>>thres;
    int low = 1,high = 1;
    f(i,0,n) high = max(high,a[i]);
    while(low<high){
        int mid = (low+high)/2;
        if(poss(a,thres,mid))
            high = mid;
        else
            low = mid+1;
    }
    cout<<low<<endl;
}