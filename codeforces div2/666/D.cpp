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
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        f(i,0,n) cin>>a[i];
        sort(all(a));
        multiset<int> s;
        f(i,0,n) s.insert(a[i]);
        while(s.size()>1){
            int a = *s.rbegin();
            int b = *(++s.rbegin());
            s.erase(s.find(b));
            s.erase(s.find(a));
            if(a!=1) s.insert(a-1);
            if(b!=1) s.insert(b-1);
        }
        if(s.size()==0) cout<<"HL"<<endl;
        else cout<<"T"<<endl;

    }

}