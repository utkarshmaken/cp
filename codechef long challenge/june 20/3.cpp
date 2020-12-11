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
const int maxn = 200000;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    f(i,0,n) cin>>a[i]; 
    vector<int> coin(3);
    f(i,0,n){
        if(a[i] == 5)
            ++coin[0];
        else if(a[i]==10){
            if(coin[0]>0){
                ++coin[1];
                --coin[0];
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
        else{
            if(coin[1]>0)
                --coin[1];
            else if(coin[0]>1)
                coin[0]-=2;
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
        
        


    }

}