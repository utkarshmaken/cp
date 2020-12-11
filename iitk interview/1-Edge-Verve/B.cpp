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
    string s;
    cin>>s;
    int n = s.size();
    int ans = 0;
    f(i,0,n){
         int num = 0;
        repd(j,i,0){
            int  k = s[j]-'a';
            num = num^(1<<k);
            if(num==0 || !(num&(num-1)) )
                ans++;
        }
    }
    cout<<ans<<endl;
 
} 
/*int main(){
    string s;
    cin>>s;
    int n = s.size();
    vector<vector<int>> freq(n+1,vector<int>(26,0));
    f(i,0,n){
        freq[i+1] = freq[i];
        freq[i+1][s[i]-'a']++;
    }
    int ans = 0;
    f(i,0,n){
        ans++;
        repd(j,i-1,0){
            int odd = 0;
            f(k,0,26)
                odd+=((freq[i+1][k]-freq[j][k])&1);
            if(odd==0 || odd==1)
                ans++;
        }
    }
    cout<<ans<<endl;

}*/