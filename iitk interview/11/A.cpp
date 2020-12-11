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
    int n;cin>>n;
    vector<int> a(n);
    f(i,0,n) cin>>a[i];
    vector<int> price(n);
    ll sum = a[n-1];;
    stack<int> s;s.push(n-1);
    stack<int> ans;ans.push(n-1);
    repd(i,n-2,0){
        while(!s.empty() && a[i] < a[s.top()])
            s.pop();
        if(!s.empty())
            sum+=a[i]-a[s.top()];
        else{
            ans.push(i);
            sum+=a[i];
        }

        s.push(i);
    }
    cout<<sum<<endl;
    while(!ans.empty()){
        cout<<ans.top()<<' ';
        ans.pop();
    }
}
