//FIND THE SUBSTRING
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
int findKMP(string s, string p, int n, int m){
    vector<int> lps(m,0);
    int i = 1,len = 0,j;
    while(i<m){
        if(p[i] == p[len]){
            ++len;
            lps[i] = len;
            ++i;
        }
        else{
            if(len!=0)
                len = lps[len-1];
            else
                ++i;
        }
    }
    i = 0,j = 0;
    while(i<n){
        if(s[i] == p[j]){
            ++i;++j;
        }
        if(j==m) return i-m;
        else if(i<n && p[j]!=s[i]){
            if(j!=0)
                j = lps[j-1];
            else
                ++i;
        }
    }
    return -1;
}
int main(){
    string s,x;
    cin>>s>>x;
    int n = s.size(),m = x.size();
    int idx = -1;
    f(i,0,m){
        if(x[i]=='*'){
            idx = i;
            break;
        }
    }
    if(idx==-1){
        int ans = findKMP(s,x,n,m);
        cout<<ans<<endl;
        return 0;
    }
    int occur = -1;
    f(i,0,26){
        x[idx] = 'a' + i;
        int id = findKMP(s,x,n,m);
        if(id==-1) continue;
        if(occur==-1) occur = id;
        else occur = min(occur,id);
    }
    cout<<occur<<endl;


}