//NICE TEAMS

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
    int n;cin>>n;
    vector<int> rating(n);
    f(i,0,n) cin>>rating[i];
    int diff;cin>>diff;
    sort(all(rating));
    vector<bool> visited(n,false);
    int ans = 0;
    int i = 0,j = 1;
    while(j<n){
        if(visited[i]){
            ++i;
            continue;
        }
        while(j<n && (rating[j]-rating[i]<diff)) ++j;
        if(j<n){
            ++ans;
            ++i;
            visited[j++] = true;
        }
    }
    cout<<ans<<endl;
}