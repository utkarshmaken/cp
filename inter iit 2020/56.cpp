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
    int n1,n2;
    cin>>n1>>n2;
    if(n1 > n2) swap(n1,n2);
    int ans = 0;
    int s = 1;
    while(true){
        int needed = s*(s+1)/2;
        if(n1>=needed && n2>=needed){
            ans+=s+1;
            n1-=needed;
            n2-=needed;
            ++s;
        }
        else
            break;
    }
    
    for(int i = 0,j = s;n1>=i && n2>=j;++i,--j){
        ++ans;
        n1-=i;
        n2-=j;
    }
    cout<<ans<<endl;



}