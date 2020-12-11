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
vector<char> vowel = {'a','e','i','o','u'};
bool is_vowel(char &c){
    for(auto &ch:vowel)
        if(c==ch) return true;
    return false;
}
int main(){
    int n ;
    cin>>n;
    vector<ll> sum(n+1);
    rep(i,1,n){
        string s;
        cin>>s;
        sum[i] = sum[i-1];
        if(is_vowel(s[0]) && is_vowel(s[sz(s)-1]))
            sum[i]+=1;
    }
    int q;
    cin>>q;
    f(i,0,q){
        int l,r;
        char t;
        cin>>l;
        cin>>t;
        cin>>r;
        cout<<sum[r]-sum[l-1]<<endl;
    }

}
