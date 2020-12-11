//MINIMUM WINDOW SUBSTRING
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

int main(){
    string s,t;
    cin>>s>>t;
    int n = s.size(),len = t.size();
    map<char,int> m;
    for(auto &x:t) ++m[x];
    int start = 0,i = 0;
    int found = 0,mini = INT_MAX,start_f;
    map<char,int> freq;
    while(i<=n){
        if(i<n && found<len){
            if(freq[s[i]] < m[s[i]]) ++found;
            ++freq[s[i]];
            ++i;
        }
        else{
            if(i==n && found!=len) break;
            while(freq[s[start]] > m[s[start]]){
                --freq[s[start]];
                ++start;
            }
            if(i - start < mini){
                mini = i-start;
                start_f = start;
            }
            --freq[s[start++]];
            --found;
        }
    }
    if(mini == INT_MAX) cout<<""<<endl;
    else cout<<s.substr(start_f,mini)<<endl;
}