//Count substrings that contain all vowels
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
const int maxn = 2e5;
bool isvowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        return true;
    return false;
}
int main(){
    string s;
    cin>>s;
    s = s+'z';
    int n = sz(s);
    int start = 0,ans = 0;
    f(i,0,n){
        if(isvowel(s[i]))
            continue;
        else{
            if(i== start){
                ++start;
                continue;
            }
            map<char,int> freq;
            int count = 0;
            f(j,start,i){
                if(freq[s[j]] == 0) ++count;
                freq[s[j]]++;
                while(count == 5){
                    ans+=(i-j);
                    if(freq[s[start]] == 1) --count;
                    --freq[s[start++]];
                }
            }
            start = i+1;
        }
    }
    cout<<ans<<endl;

   
}