//UNLOCKING KEY
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
int to_int(string &s){
    int n = s.size();
    int res = 0;
    for(int i = 0;i<n;i++){
        int digit = s[i]-'0';
        res = res*10 + digit;
    }
    return res;
}
int main(){
    int k;
    cin>>k;
    k = abs(k);
    vector<int> freq(10,0);
    while(k!=0){
        int digit = k%10;
        freq[digit]+=1;
        k = k/10;
    }
    string ans = "";
    int smallest = 0;
    for(int i = 1;i<=9;i++){
        if(freq[i]!=0){
            smallest = i;
            break;
        }
    }
    ans+=('0' + smallest);
    freq[smallest]-=1;
    for(int j = 0;j<freq[0];j++) ans+='0';
    for(int i = smallest;i<=9;i++){
        for(int j = 0;j<freq[i];j++)
            ans+=('0' + i);
    }
    int res = to_int(ans);
    cout<<ans<<endl;
}