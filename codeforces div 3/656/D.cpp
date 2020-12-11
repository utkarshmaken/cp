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
int solve(string s, int n,char ch){
    if(n==1){
        return !(s[0]==ch);
    }
    int l = 0,r = 0;
    f(i,0,n/2)
        if(s[i]==ch)
            l++;
    f(i,n/2,n)
        if(s[i]==ch)
            r++;
    int a1 = n/2 - l + solve(s.substr(n/2),n/2,ch+1);
    int a2 = n/2 - r + solve(s.substr(0,n/2),n/2,ch+1);
    return min(a1,a2);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<solve(s,n,'a')<<endl;

    }

}