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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        f(i,0,n) cin>>a[i];
        vector<int> num(32,0);
        int maxi = -1;
        f(i,0,n){
            int idx = 0;
            while(a[i]!=0){
                num[idx++]+= (a[i]&1);
                a[i] = a[i]>>1;
            }
            maxi = max(maxi,idx-1);
        }
        if(maxi==-1){
            cout<<"DRAW"<<endl;
            continue;
        }
        bool flag = false;
        repd(i,maxi,0){
            int ones = num[i],zeros = n-num[i];
            if(!(ones&1))
                continue;
            if(ones%4==3 && zeros%2==0)
                cout<<"LOSE"<<endl;
            else
                cout<<"WIN"<<endl;
            flag = true;break;
            
        }
        if(!flag)
            cout<<"DRAW"<<endl;
    }

}