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

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n+1);
        rep(i,1,n)
            cin>>v[i];
        
        int l = 1,r = n;
        while(l<=n &&v[l]==l)
            l++;
        while(r>0 && v[r]==r)
            r--;
        if(l==n+1)
            cout<<"0"<<endl;
        else{
            bool flag = false;
            rep(i,l,r){
                if(v[i]==i){
                    flag = true;
                    break;
                }
            }
            if(flag)
                cout<<"2"<<endl;
            else
                cout<<"1"<<endl;
                
        }
        
    }

}