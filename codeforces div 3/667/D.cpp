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
    int t;cin>>t;
    while(t--){
        ll n,s;
        cin>>n>>s;
        vector<int> digits;
        ll temp = n,sum = 0;
        while(temp>0){
            sum+=temp%10;
            digits.pb(temp%10);
            temp/=10;
        }
        if(sum<=s){
            cout<<0<<endl;
            continue;
        }

        int diff = sum-s;
        ll ans = 0,i = 0,maxi;
        while(digits[i]==0) ++i;
        if(diff>digits[i] && i!=(sz(digits)-1)){
            ans+=(10-digits[i])*pow(10,i);
            diff-=digits[i];i++;
        }

        for(;i<sz(digits) && diff>0;++i){
            maxi = digits[i];
            if(maxi==0){
                continue;
            }
            if(diff>maxi && i!=(sz(digits)-1)){
                ans+=(10-maxi-1)*pow(10,i);
                diff-=maxi;
            }
            else if(i==sz(digits)-1){
               break;
            }
            else{
                if(ans==0) ans+=(10-maxi)*pow(10,i);
                else ans+=(10-maxi-1)*pow(10,i);
                diff-=maxi;
                int i1 = i+1;
                while(i1!=(sz(digits)-1) && (digits[i1]==9||digits[i1]==0)){
                    if(digits[i1]==0){
                        ++i1;continue;
                    }
                    ans+=(10-digits[i1]-1)*pow(10,i1);
                    ++i1;
                }
                i=i1;
                if(i==sz(digits)-1 && diff==0) break;
                if(i==sz(digits)-1) ans+=0;
                else ans+=(10-digits[i]-1)*pow(10,i);
            }
        }

        if(i==sz(digits)-1){
            ll a = pow(10ll,sz(digits));
            ll ans = a - n;
            cout<<ans<<endl;
        }
        else
           cout<<ans<<endl;
        
       

    }

}