//MERGING PALINDROMES
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
    string s1,s2;
    cin>>s1>>s2;
    vector<int> freq1(26),freq2(26);
    f(i,0,sz(s1)) freq1[s1[i] - 'a']++;
    f(i,0,sz(s2)) freq2[s2[i] - 'a']++;
    vector<int> freq(26);
    int omax = 0,idx;
    f(i,0,26){
        if(freq1[i]%2 == 0) freq[i]+=freq1[i];
        if(freq2[i]%2 == 0) freq[i]+=freq2[i];
        
        if(freq1[i]%2 == 1 && freq2[i]%2 == 1){
            if(freq1[i] + freq2[i] > omax){
                omax = freq1[i] + freq2[i];
                idx = i;
            }
        }
        else if(freq1[i]%2 == 1 && freq1[i]>omax){
            omax = freq1[i];
            idx = i;
        }
        else if(freq2[i]%2 == 1 && freq2[i]>omax){
            omax = freq2[i];
            idx = i;
        }
    }
    freq[idx]+=omax;
    string ans = "";
    string c = "";
    f(i,0,26){
        ans+=string(freq[i]/2,'a'+i);
        if(freq[i]&1) c+=('a'+i);
    }
    ans = ans + c + string(ans.rbegin(),ans.rend());
    cout<<ans<<endl;




}