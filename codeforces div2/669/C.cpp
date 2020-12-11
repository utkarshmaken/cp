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
    vector<int> ans(n+1);
    set<int> s;
    rep(i,1,n) s.insert(i);
    int q1,q2;
    string ques = "? ";
    while(s.size()!=1){
        int i = *s.begin();
        int j = *(++s.begin());
        string str = ques  + to_string(i) + " " + to_string(j);
        cout<<str<<endl;
        cout.flush();
        cin>>q1;
        str = ques + to_string(j) + " " + to_string(i);
        cout<<str<<endl;
        cout.flush();
        cin>>q2;
        if(q1>q2){
            ans[i] = q1;
            s.erase(i);
        }
        else{
            ans[j] = q2;
            s.erase(j);
        }
    }
    int sum = n*(n+1)/2;
    for(int i = 1;i<=n;i++) sum-=ans[i];
    rep(i,1,n) if(ans[i]==0) ans[i] = sum;
    string  res = "! ";
    rep(i,1,n) res+=to_string(ans[i]) + " ";
    cout<<res<<endl;
    cout.flush();
}