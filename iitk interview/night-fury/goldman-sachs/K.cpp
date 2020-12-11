//MESSAGING FRIENDS
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

int bin_ones(map<char,int> &one_count){
    int res = 0;
    rep(i,'a','z'){
        int n = i;
        int one = 0;
        while(n!=0){
            one+=(n&1);
            n = n>>1;
        }
        one_count[i] = one;
    }
}
string find(string str, int p){
    string res = "";
    str+=' ';
    map<char,int> one_count;
    bin_ones(one_count);

    int curr = 0, pos = str.find(' '), len = str.size();
    while(pos < len){
        string s = str.substr(curr,pos-curr);
        int ones = 0, n = s.size();
        for(auto &ch:s){
            ch = tolower(ch);
            ones+=one_count[ch];
        }
        int shift = ones - p;
        shift%=n;
        if(shift)
            s = s.substr(n-shift) + s.substr(0,n-shift);
        res+=s;
        res+=" ";

        curr = ++pos;
        if(pos >= len) break;
        pos = str.find(' ',pos);
    }
    res.pop_back();
    return res;
}

int main(){
    string str;
    getline(cin,str);
    int p;
    cin>>p;
    cout<<find(str,p)<<endl;
}