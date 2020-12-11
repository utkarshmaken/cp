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

int main(){
    int t;
    cin>>t;
    while(t--){
       int n,k;
       cin>>n>>k;
       vector<ll> arr(n);
       vector<ll> rem(n);
       f(i,0,n){
           cin>>arr[i];
           rem[i] = k - (arr[i]%k ==0?k:arr[i]%k);
       }
       sort(all(rem));
       ll start=0,i;
       ll done = 0,x=0,moves=0;
       while(start<n){
           if(rem[start]==0){
            done++;
            start++;
           }
           else{
           ll j = start+1;
           while(j<n && rem[j]==rem[start]){
                rem[j]+=(j-start)*k;
                j++;
           }
            start = j;
           }
       }
       sort(all(rem));
       while(done!=n){
           ll needed = rem[done];
           while(x<=needed){
               moves++;
               x++;
           }
           done++;
       }
       cout<<moves<<endl;


    }

}