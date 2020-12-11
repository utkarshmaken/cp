//SMALLEST INTEGER WITH DIGIT SUM M AND MULTIPLE OF N
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
int do_sum(int n){
    int sum = 0;
    while(n!=0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main(){
    int n,m;
    cin>>n>>m;
    int dig = m/9;
    ll start = pow(10,dig) - ((int)pow(10,dig)%n);
    while(start < INT_MAX){
        if(do_sum(start) == m){
            cout<<start<<endl;
            break;
        }
        else{
            start+=n;
        }
    }

}