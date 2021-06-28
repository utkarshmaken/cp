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
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        set<char> done;
        int i = 0;
        bool ans = true;
        while(i < n){
            int j = i + 1;
            while(j < n && s[j] == s[i]) ++j;
            if(done.find(s[i]) != done.end()){
                ans = false;
                break;
            }
            done.insert(s[i]);
            i = j;
        }
        cout<<(ans ? "YES" : "NO")<<endl;
    }

}