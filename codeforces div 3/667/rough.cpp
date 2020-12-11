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
const int maxn = 100001;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n);
        f(i,0,n) cin>>v[i];
        vector<int> left(n),leftf(n);
        left[0] = 0,leftf[0] = -1;
        f(i,1,n){
            int maxi = 0,idx = -1,cnt = 0;
            repd(j,i-1,0){
                if(v[j]>v[i]){
                    ++cnt;
                    if(v[j]>maxi){
                        maxi = v[j];
                        idx = j;
                    }
                }
                
            }
            left[i] = cnt;
            leftf[i] = idx;
        }

        int mini = 10,maxi = 1;
        f(i,0,n){
            int s = v[i];
            if(leftf[i]!=-1) 
                s = v[leftf[i]];
            int ans = 1,min_s = v[i];
            f(j,i+1,n){
                if(v[j]<s){
                    ++ans;
                    min_s = min(min_s,v[j]);
                }
            }
            repd(j,i-1,0){
                if(v[j]>min_s)
                    ++ans;
            }
            mini = min(mini,ans);
            maxi = max(maxi,ans);
        }
        cout<<mini<<' '<<maxi<<endl;

    }

}