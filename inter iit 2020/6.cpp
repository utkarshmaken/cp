//PERSONALIZED TYPEWRITER
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
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    map<pii,int> freq;
    f(i,1,n){
        int a = s[i-1]-'a';
        int b = s[i] - 'b';
        if(a>b) swap(a,b);
        freq[{a,b}]+=1;
    }
    int ans = 0;
    
    


    

}