//Longest-Healthy-String
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
    //O(n*26*26)
    int n;
    cin>>n;
    vector<string> s(n);
    f(i,0,n) cin>>s[i];
    vector<int> len(n);
    f(i,0,n) len[i] = sz(s[i]);
    int ans1 = 0;
    f(i,0,26){
        f(j,0,26){
            int f = 0;
            int state = 0,len1 = 0,len2 = 0,lent = 0;
            f(k,0,n){
                if(s[k][0]=='a'+i  && s[k].back()=='a'+j)
                    len1 = max(len1,len[k]);
                if(s[k][0]=='a'+)
            }
        }
    }





}