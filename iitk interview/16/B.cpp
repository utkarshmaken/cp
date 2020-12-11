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
   string s;
   cin>>s;
   int n = s.size();
   set<int> chars;
   for(auto ch:s) chars.insert(ch);
   int ans = n+1,start = 0;
   map<int,int> freq;
   for(int i = 0;i<n;i++){
       chars.erase(s[i]);
       freq[s[i]]++;
       if(chars.empty()){
           ans = min(ans,i-start+1);
           while(freq[s[start]]>1){
                freq[s[start]]--;
                start++;
                ans = min(ans,i-start+1);
            }
            chars.insert(s[start]);
            freq[s[start]]--;
            start++;
        }

    }
    cout<<ans<<endl;
}