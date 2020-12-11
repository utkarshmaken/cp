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
    int t;
    cin>>t;
    while(t--){
        int r,g,b,w;
        cin>>r>>g>>b>>w;
        int odd = 0;
        if(r&1) odd++;
        if(g&1) odd++;
        if(b&1) odd++;
        if(odd==0 || odd==3)
            cout<<"Yes"<<endl;
        else if(odd==1){
            if(!(w&1))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        else if(odd==2){
            if(!(w&1))
                cout<<"No"<<endl;
            else{
                if(r>0 && g>0 && b>0)
                    cout<<"Yes"<<endl;
                else
                    cout<<"No"<<endl;
            }
        }
       
    }
}