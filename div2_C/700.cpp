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

int main(){
    int n;
    cin>>n;
    int low = 1, high = n;
    while(low != high ){
        int m1 = (low + high) / 2, a1;
        int m2 = m1 + 1, a2;
        cout<<"? "<< m1<<endl;
        cout.flush();
        cin>>a1;
        cout<<"? "<< m2<<endl;
        cout.flush();
        cin>>a2;
        if(a1 < a2)   high = m1;
        else low = m2;
    }
    
    cout<<"! "<<low<<endl;
    cout.flush();
}