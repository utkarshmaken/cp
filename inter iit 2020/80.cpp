//NUMBER OF STEPS TO MAIN DIRECTORY
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
const int maxn = 1e5;

int main(){
    int n;
    cin>>n;
    vector<string> moves(n);
    f(i,0,n) cin>>moves[i];
    int dist = 0;
    f(i,0,n){
        if(moves[i] == "x/") ++dist;
        else if(moves[i] == "../" && dist!=0) --dist;
    }
    cout<<dist<<endl;
}