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
using namespace std;
const int mod = 1000000007;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int l = 0,r = n-1;
        while(l<n && s[l]=='0')
            l++;
        while(r>=0 && s[r] =='1')
            r--;
        if(l>r)
            cout<<s<<endl;
        else
            cout<<s.substr(0,l) + "0" +  s.substr(r+1)<<endl;
    }

}