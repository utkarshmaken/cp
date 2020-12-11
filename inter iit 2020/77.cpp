//WEIRD FACULTY
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
    int n;
    cin>>n;
    vector<int> v(n);
    f(i,0,n) cin>>v[i];
    vector<int> sum(n+1);
    f(i,0,n) sum[i+1] = sum[i] + v[i];
    f(k,0,n){
        int score1 = (2*sum[k] - k);
        int score2 = (2*(sum[n]-sum[k]) - (n-k));
        if(score1 > score2){
            cout<<k<<endl;
            break;
        }
    }
}