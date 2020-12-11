//BEAUTIFUL STRING
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
#define endl '\n'
using namespace std;
const int mod = 1000000007;
const int maxn = 100001;

int main(){
    string s;cin>>s;
    int n = sz(s);
    int start = 0,ans = 0;
    unordered_map<char,int> freq;char ch = '?';
    f(i,0,n){
        freq[s[i]]++;
        if(freq[s[i]]>1) ch = s[i];
        while(ch!='?'){
            freq[s[start++]]--;
            if(freq[ch]==1) ch = '?';
        }
        ans+=(i-start+1);   
    }
    cout<<ans<<endl;

}