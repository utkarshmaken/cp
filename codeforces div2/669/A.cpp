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
    vector<int> grt(n),less(n),grtp(n),lessp(n);
    grt[n-1] = -1;
    stack<int> s;s.push(n-1);
    repd(i,n-2,0){
        while(!s.empty() && a[s.top()]<a[i])
            s.pop();
        if(s.empty()) grt[i] = -1;
        else grt[i] = s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    less[n-1] = -1;
    s.push(n-1);
    repd(i,n-2,0){
        while(!s.empty() && a[s.top()]>a[i])
            s.pop();
        if(s.empty()) less[i] = -1;
        else less[i] = s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    grtp[0] = -1;
    rep(i,1,n){
        while(!s.empty() && a[s.top()]<a[i])
            s.pop();
        if(s.empty()) grtp[i] = -1;
        else grtp[i] = s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    lessp[0] = -1;
    rep(i,1,n){
        while(!s.empty() && a[s.top()]>a[i])
            s.pop();
        if(s.empty()) lessp[i] = -1;
        else lessp[i] = s.top();
        s.push(i);
    }
    int i = 0;int ans = 0;
    while(i<n-1){
        if(a[i+1]==a[i]){
            ++i;++ans;continue;
        }
        if(a[i+1]>a[i]){
            int end = less[i];
            if(end==-1){
                ++ans;++i;continue;
            }
            while(!(lessp[end]<=i)) end--;
            ++ans;i = end;
        }
        else{
            int end = grt[i];
            if(end==-1){
                ++i;++ans;continue;
            }
            while(!(grtp[end]<=i)) end--;
            ++ans;i = end;
        }
    }
    cout<<ans<<endl; 
}