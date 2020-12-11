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
    int n,t,x;
    cin>>n>>t>>x;
    vector<int> arr(x);
    f(i,0,x) cin>>arr[i];
    f(i,0,x) arr[i]%=n;
    int ti = 0;
    vector<int> avail(n,0);
    f(i,0,x){
        int j = arr[i],mini = INT_MAX,idx;
        int k = j;bool flag = false;
        while(k<n){
            if(avail[k]>ti){
                if(avail[k]-ti<mini){
                    mini = avail[k] - ti;
                    idx = k;
                }
            }
            else{
                cout<<k<<endl;
                avail[k]+=t;
                flag =  true;
                break;
            }
            k++;
        }
        if(flag){
            ti++;continue;
        }
        k = 0;
        while(k<j){
            if(avail[k]>ti){
                if(avail[k]-ti<mini){
                    mini = avail[k] - ti;
                    idx = k;
                }
            }
            else{
                cout<<k<<endl;
                avail[k]+=t;
                flag =  true;
                break;
            }
            k++;
        }
        if(flag){
            ti++;continue;
        }
        cout<<idx<<endl;
        avail[idx]+=t;
        ti+=mini;
        ti++;
    }
    



}